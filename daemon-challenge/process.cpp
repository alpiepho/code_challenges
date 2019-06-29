#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <thread>

#include "process.h"
#include "socket.h"
#include "utils.h"

using namespace std;

Process::Process() {
    _pauseRequested = false;
    _endRequested   = false;
    port            = DEFAULT_PORT;
    interval        = DEFAULT_SAMPLE_INTERVAL_MS;
    _dataStore      = new DataStore();
}

Process::~Process() {
    if (_dataStore) {
        delete _dataStore;
        _dataStore = NULL;
    }
}

void Process::inMem(bool value) {
    if (_dataStore) {
        _dataStore->inMem = value;
    }
}

void Process::maxSamples(int value) {
    if (_dataStore) {
        _dataStore->maxSamples = value;
    }
}

void Process::fileName(string value) {
    if (_dataStore) {
        _dataStore->fileName = value;
    }
}

float Process::sample() {
    // get random value
    float value = 10.0 * ( static_cast <float> (rand()) / static_cast <float> (RAND_MAX) );
    return value;
}

void * Process::staticLoop(void *c) {
    ((Process *) c)->loop();
    return NULL;
}

void Process::loop() {
    _dataStore->open();
    while (1) {
        // control sample rate
        Utils::sleep(interval);

        // check exit conditions
        if (_dataStore->isFull())
            break;
        if (_endRequested)
            break;

        // check paused
        if (!_pauseRequested) {
            _dataStore->record(sample());
        }
    }
}

void * Process::staticCmds(void *c) {
    ((Process *) c)->cmds();
    return NULL;
}

void Process::cmds() {
    Socket *socket = new Socket();
    socket->open(port);

    while (1) {
        string cmd = socket->next();
        if (cmd == "pause") {
            _pauseRequested = true;
        }
        else if (cmd == "resume") {
            _pauseRequested = false;
        }
        else if (cmd == "end") {
            _endRequested = true;
            break;
        }
        else if (cmd == "read") {
            _dataStore->readPrep();
            string line = _dataStore->readNext();
            while (!line.empty()) {
                socket->send(line);
                line = _dataStore->readNext();
            }
        }
    }

    delete socket;
}

void Process::run() {
#ifdef DEBUG
    cout << "inMem:      " << std::boolalpha <<  _dataStore->inMem << endl;
    cout << "port:       " << port << endl;
    cout << "interval:   " << interval << endl;
    cout << "maxSamples: " << _dataStore->maxSamples << endl;
    cout << "fileName:   " << _dataStore->fileName << endl;
    pid_t PID = getpid();
    cout << "The PID of the current process: " << PID << endl;
#endif

    pthread_create(&_loopThread, NULL, Process::staticLoop, this);
    pthread_create(&_cmdsThread, NULL, Process::staticCmds, this);

    while (!_endRequested) {
        Utils::sleep(1000);
    }

    void* ret;
    ret = NULL;
    pthread_join (_loopThread, &ret);
    ret = NULL;
    pthread_join (_cmdsThread, &ret);
}
