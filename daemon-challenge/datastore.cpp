#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "utils.h"
#include "datastore.h"

using namespace std;

DataStore::DataStore() {
    inMem           = 0;
    _samples        = 0;
    _file           = NULL;
    maxSamples      = DEFAULT_SAMPLE_MAX_COUNT;
    fileName        = DEFAULT_FILE_NAME;
}

DataStore::~DataStore() {
    if (inMem) {
        dump();
    }

    if (_file) {
        _file->close();
        delete _file;
        _file = NULL;
    }
}

void DataStore::open() {
    _file = new ofstream(fileName);
    if (!_file) {
        Utils::error("ERROR: could not open data store");
    }
    if (maxSamples < 0 || maxSamples > DataStore::DEFAULT_SAMPLE_MAX_COUNT) {
        Utils::error("ERROR: maxSamples is too large");
    }
}

void DataStore::record(float value) {
    unsigned long timestamp = Utils::timestamp();
#ifdef DEBUG
    cout << "samples: " << _samples << "; " << timestamp << ", " << value << endl;
#endif
    //NOTE: keeping memory copy of values, even for file mode. saves reading from file.
    //      might need to revisit if datastore needs to roll over.
    _mutex.lock();
    _timestampArray[_samples] = timestamp;
    _valueArray[_samples] = value;
    _mutex.unlock();

    if (!inMem) {
        try {
            _mutex.lock();
            *_file << timestamp << ", " << value << endl;
             _mutex.unlock();
        } catch(ofstream::failure &writeErr) {
             _mutex.unlock();
            Utils::error("ERROR: file write error");
        } catch(std::exception &err) {
            _mutex.unlock();
            //NOTE: not sure this is a good thing inside a daemon
            throw err;
        }
    }
    _samples += 1;
}

bool DataStore::isFull() {
    return (_samples > maxSamples);
}

void DataStore::dump() {
    for (int i = 0 ; i < _samples; i++) {
        *_file << _timestampArray[i] << ", " << _valueArray[i] << endl;
    }
}

void DataStore::readPrep() {
    _readIndexStart = 0;
    _readIndexCurrent = 0;
    _readIndexEnd = _samples-1;
}

string DataStore::readNext() {
    string result = "";
    if (_readIndexEnd >= 0 && _readIndexCurrent <= _readIndexEnd) {
        stringstream ss;
        int i = _readIndexCurrent;
        _mutex.lock();
        ss << _timestampArray[i] << ", " << _valueArray[i] << endl;
        _mutex.unlock();
        _readIndexCurrent += 1;
        result = ss.str();
    }
    return result;
}
