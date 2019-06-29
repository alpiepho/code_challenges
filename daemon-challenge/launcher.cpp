#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#include "utils.h"
#include "process.h"
#include "launcher.h"

int lock_daemon(int sid) {
    //NOTE: might be difficult to convert to C++ due to lock
    char buf[10];
    int fp = open(DEFAULT_LOCK_NAME, O_RDWR|O_CREAT, 0640);
    if (fp < 0) return fp;                  // cannot open
    if (lockf(fp,F_TLOCK,0) < 0) return fp; // cannot lock
    sprintf(buf, "%d\n", sid);
    write(fp, buf, strlen(buf));
    return fp;
 }

void signal_handler(int sig) {
    switch (sig) {
        case SIGHUP:
            Utils::log("SIGHUP caught");
            break;
        case SIGTERM:
            Utils::log("SIGTERM caught");
            exit(EXIT_SUCCESS);
            break;
    }
}

void Launcher::run(Process *process) {
    Utils::log("(parent) launching daemon started");

    pid_t pid; // child or parent process id
    pid_t sid; // new session/group id for child

    pid = fork();

    // error with fork
    if (pid < 0) {
        delete process;
        Utils::log("(parent) ERROR: launching daemon fork failed");
        exit(EXIT_FAILURE);
    }

    // parent continues with pid > 0
    if (pid > 0) {
        delete process;
        Utils::log("(parent) launching daemon finished");
        exit(EXIT_SUCCESS);
    }

    // NOTE: in child context from here on

    // clear umask so child (daemon) process can write files/logs
    umask(0);
    Utils::log("(child) daemon started");

    // get new session/group for child
    sid = setsid();

    // error with setsid
    if (sid < 0) {
        delete process;
        Utils::log("(child) ERROR: setsid failed");
        exit(EXIT_FAILURE);
    }

    // change to known existing directory
    if ((chdir("/") < 0)) {
        delete process;
        Utils::log("(child) ERROR: chdir failed");
        exit(EXIT_FAILURE);
    }

    // lock daemon
    int lock = lock_daemon(sid);

    // error with lock
    if (lock < 0) {
        delete process;
        Utils::log("(child) ERROR: lock create failed");
        exit(EXIT_FAILURE);
    }
    if (lock == 0) {
        delete process;
        Utils::log("(child) ERROR: lock lock failed");
        exit(EXIT_SUCCESS);
    }

    // daemon cannot use terminal, close standard descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // handle signals per New Style recommendation
    signal(SIGCHLD, SIG_IGN);        // child stopped
    signal(SIGTSTP, SIG_IGN);        // stop, typically from user
    signal(SIGTTOU, SIG_IGN);        // background attempt writing to terminal
    signal(SIGTTIN, SIG_IGN);        // background attempt reading from terminal
    signal(SIGHUP,  signal_handler); // hangup when terminal closed
    signal(SIGTERM, signal_handler); // kill

    // let child do it'sthing
    process->run();

    // cleanup
    delete process;
    Utils::log("(child) daemon finished");
    exit(EXIT_SUCCESS);
}
