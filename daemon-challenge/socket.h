#ifndef _SOCKET_H
#define _SOCKET_H

#include <iostream>

class Socket {
    int _socketFd;
    int _acceptFd;

public:
    Socket();
    ~Socket();
    void open(int port);
    std::string next();
    void send(std::string line);
};

#endif // _SOCKET_H