### The Problem 
 From email:

 Linux Programming Challenge,

Write a program in C++ that,

- Can be launched as a Daemon with the command line flag “-d" - **done**
- Appends random data to a file every 250ms - **done**
- Data is a number between 0.0 and 10.0 with time stamp and is separated by new line - **done**
- Listens on TCP port 9000 - **done**
- On receiving “pause” on that port pauses writing to the file - **done**
- On receiving “resume” on that port resumes writing to the file - **done**
- On receiving “end” on the port gracefully terminates the program - **done**
- Can be compiled in any Linux distribution including custom Linux system (i.e. can be cross-compiled for ARM systems) - **done**

Bonus,
- Append the same data described above to memory instead of a file with the command line flag “-mem" - **done**
- Save the data stored in memory to a file when terminating the program (only valid if “-mem” flag was used) - **done**
- On receiving “read” on TCP port 9000 send the content of the file or memory to the client - **done**

Let me know if you have a questions. The deadline for completion is midnight Monday but let me know if you need more time.

### Assumptions to Verify:

1. Assuming data file is a text/csv file, with timestamp, value per line.
2. Assuming file can be limited by command line parameter.
3. Assuming if there are file errors, like too big, that sampling stops, but application does not.
4. Assuming each run of the application replaces the data file.
5. Data file is saved as /tmp/samplerd.csv.
6. Assuming we don't need memory buffering in front of appending file, ie. file IO is fast enough.
7. Assuming the problem is to see how I would code the daemon process algorithm, so that implemetation is minimal.  See the Issues/Concerns section for a decsription of the 4 deamonization methods I found.
8. Simplified read operation, by using the memory cache in datastore for both modes.  Will likely need to be revised if any kind of memory rollover is implemented.

**Estimated time to get to 80% solution: 12 hours** 

### How to Build:
There is a simple Makefile:
> make all

### How to Exercise Port:
I used telnet to exersize the port. Examples for Max and Raspberry Pi, telnet from Mac:
> telnet localhost 9000

> telnet 192.168.0.105 9000

If telnet is not available, I think we can 'netcat' or 'nc', with echo.

### How this was Tested:
There are no unit-tests at this point.  There could be around the sample_loop code.  Unit tests for the comand parsing and port operations might be more difficult.

Testing was limited to manual testing on a Mac and a Raspberry Pi running Raspian.  A specific custom Linux build (with tool chain) would be needed to test if this application would build and run there.

If this code was going to production, I would look at how to verify memory usage and performance, such as how accurate the sample timing is.

### Issues and Concerns:
- Will the time stamps method port over to a custom Linux easily?
- Will the ms sleep port over to a custom Linux?
- Currently ANY exceptions when sampling and writing data causes the sample loop to end, but the port listening thread continues.  Is this ok?
- Researching how daemonize a linux app, I found four methods:
    1. Old SysV
    2. New-Style
    3. Using deamon() which appearently is deprecated (at leaston Mac)
    4. Do nothing and allow systemd to handle it (see reference below)
- Chose to follow steps similar to the SysV method
- Chose to log to a file in /tmp rather than figure out systemd log and Mac alternative

Credits/References
-

Methods for sleep in ms in C++:

http://www.martinbroadhurst.com/sleep-for-milliseconds-in-c.html

Tutorial on C++ file IO:

http://www.cplusplus.com/doc/tutorial/files/

Concepts for Linux Sockets in C++:

http://www.linuxhowtos.org/C_C++/socket.htm

Concept of Daemonizing:

from 2001: http://www.enderunix.org/docs/eng/daemon.php

from 2004: http://www.netzmafia.de/skripten/unix/linux-daemon-howto.html

from 2017: https://gist.github.com/alexdlaird/3100f8c7c96871c5b94e

SysV vs New Style: https://stackoverflow.com/questions/17954432/creating-a-daemon-in-linux/17955149#17955149

Do Nothing: http://blog.benoitblanchon.fr/linux-daemon-considered-harmful/




