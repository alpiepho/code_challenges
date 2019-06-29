#include <getopt.h>

#include "process.h"
#include "launcher.h"

using namespace std;

void usage() {
    printf("Usage: samplerd [-d] [-m] [-p <port>] [-i <interval>] [-s <samples>] [-f filename]\n");
    printf("       -d, --daemon    - launch as daemon\n");
    printf("       -m, --mem       - collect samples in memory buffer\n");
    printf("       -p, --port      - set port (default = 9000)\n");
    printf("       -i, --interval  - set ms interval (default = 250 ms)\n");
    printf("       -s, --samples   - set max samples (default = 1000000)\n");
    printf("       -f, --file      - set file (default = \"/tmp/sampler.csv\"\n");
}

int main(int argc, char** argv)
{
    bool asDaemon = false;
    Process *process = new Process();

    int c;
    struct option longopts[] = {
        { "daemon",   no_argument,       NULL,     'd' },
        { "mem",      no_argument,       NULL,     'm' },
        { "port",     required_argument, NULL,     'p' },
        { "interval", required_argument, NULL,     'i' },
        { "samples",  required_argument, NULL,     's' },
        { "file",     required_argument, NULL,     'f' },
        { 0, 0, 0, 0 }
    };
    while ((c = getopt_long (argc, argv, "dmp:i:s:f:", longopts, NULL)) != -1) {
        switch (c)
        {
        case 'd':
            asDaemon = true;
            break;
        case 'm':
            process->inMem(true);
            break;
        case 'p':
            process->port = stoi(optarg);
            break;
        case 'i':
            process->interval = stoi(optarg);
            break;
        case 's':
            process->maxSamples(stoi(optarg));
            break;
        case 'f':
            process->fileName(optarg);
            break;
        default:
            usage();
            return 0;
        }
    }

    srand(time(NULL));

    if (!asDaemon) {
        process->run();
    } else {
        Launcher::run(process);
    }
    delete process;

    return 0;
}
