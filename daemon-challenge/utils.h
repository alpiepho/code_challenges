#ifndef _UTILS_H
#define _UTILS_H

#include <iostream>

// didn't convert to C++ const string since mainly used in methods written as C
#define DEFAULT_FILE_NAME "/tmp/samplerd.csv"
#define DEFAULT_LOCK_NAME "/tmp/samplerd.lock"
#define DEFAULT_LOG_NAME  "/tmp/samplerd.log"

class Utils {
public:
    static void log(const char *msg);
    static void error(const char *msg);
    static unsigned long timestamp();
    static void sleep(int ms);
};

#endif //_UTILS