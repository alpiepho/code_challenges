#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

// for ms sleep, C++11
//NOTE: this might need work for custom Linux build
#include <chrono>
#include <thread>

#include "utils.h"

using namespace std;

void Utils::log(const char *msg) {
    //NOTE: should this be C++ style?
    FILE *logFd = fopen(DEFAULT_LOG_NAME, "a");
    if (logFd == 0) return;
    //TODO: add timestamp?
    fprintf(logFd, "%s\n", msg);
    fclose(logFd);
}

void Utils::error(const char *msg) {
    perror(msg);
    log(msg);
    exit(1);
}

unsigned long Utils::timestamp() {
    struct timespec now;
    clock_gettime(CLOCK_REALTIME, &now);
    unsigned long int ms = now.tv_sec * 1000 + now.tv_nsec / 1000000;
    return ms;
}

void Utils::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
