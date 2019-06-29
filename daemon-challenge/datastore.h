#ifndef _DATASTORE_H
#define _DATASTORE_H

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <mutex>

class DataStore {
public:
    static const int DEFAULT_SAMPLE_MAX_COUNT = 1000000;

private:
    unsigned long _timestampArray[DataStore::DEFAULT_SAMPLE_MAX_COUNT];
    float         _valueArray[DataStore::DEFAULT_SAMPLE_MAX_COUNT];
    std::ofstream *_file;
    int           _samples;

    // --mem specific
    std::mutex  _mutex;
    int         _readIndexStart;
    int         _readIndexCurrent;
    int         _readIndexEnd;

public:
    bool inMem;
    int maxSamples;
    std::string fileName;

    DataStore();
    ~DataStore();
    void open();
    void record(float value); 
    bool isFull();
    void dump();

    // --mem specific
    void readPrep();
    std::string readNext();
};

#endif // _DATASTORE_H