#include <iostream>
#include <fstream>

class Process;

class Launcher {
private:
    // cannot be created
    Launcher() {};

public:
    static void run(Process *process); // WARNING: this will fork and delete given process
};
