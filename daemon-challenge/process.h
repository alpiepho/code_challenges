#ifndef _PROCESS_H
#define _PROCESS_H

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>

#include "datastore.h"

class Process {
public:
    static const int    DEFAULT_PORT               = 9000;
    static const int    DEFAULT_SAMPLE_INTERVAL_MS = 250;

private:
    DataStore *_dataStore;

    // flags (shared between threads) to indicate commands
    bool _pauseRequested;
    bool _endRequested;

    pthread_t _loopThread;
    pthread_t _cmdsThread;

    float sample();

    static void * staticLoop(void * c);
    void loop();

    static void * staticCmds(void * c);
    void cmds();

public:
    int port;
    int interval;

    Process();
    ~Process();
    void inMem(bool value);
    void maxSamples(int value);
    void fileName(std::string value);
    void run();
};

#endif // _PROCESS_H