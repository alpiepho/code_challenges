#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#include <iostream>
#include <fstream>
#include <thread>

#include "socket.h"
#include "utils.h"

using namespace std;

const int    SOCKET_OPTION_ENABLE       = 1;
const int    SOCKET_BACKLOAD_SIZE       = 5;
const int    SOCKET_BUFFER_SIZE         = 256;

Socket::Socket() {
    _socketFd = -1;
    _acceptFd = -1;
}

Socket::~Socket() {
    if (_acceptFd >= 0)
        close(_acceptFd);
    if (_socketFd >= 0)
        close(_socketFd);
}

void Socket::open(int port) {
    int optval = SOCKET_OPTION_ENABLE;
    socklen_t peerAddrLen;
    struct sockaddr_in serverAddr;
    struct sockaddr_in peerAddr;

    _socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (_socketFd < 0) {
        Utils::error("ERROR: opening socket");
    }
    // have to set SO_REUSEADDR so binding is cleared when app quits
    if (setsockopt(_socketFd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) == -1) {
        Utils::error("ERROR: setting socket options");
    }
    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);
    if (bind(_socketFd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        Utils::error("ERROR: on binding");
    }
    listen(_socketFd, SOCKET_BACKLOAD_SIZE);
    peerAddrLen = sizeof(peerAddr);
    _acceptFd = accept(_socketFd, (struct sockaddr *) &peerAddr, &peerAddrLen);
    if (_acceptFd < 0) {
       Utils::error("ERROR: on accept");
    }
}

string Socket::next() {
    char buffer[SOCKET_BUFFER_SIZE];
    int transferCount;
    string result;

    bzero(buffer, SOCKET_BUFFER_SIZE);
    transferCount = read(_acceptFd, buffer, SOCKET_BUFFER_SIZE-1);
    if (transferCount < 0) {
        Utils::error("ERROR: reading from socket");
    }
#ifdef DEBUG
    cout << "socket: " << buffer << endl;
#endif
    transferCount = write(_acceptFd, "\n", strlen("\n"));
    if (transferCount < 0) {
        Utils::error("ERROR: responding to socket");
    }
    result = buffer;
    result.replace(result.find("\r"), 1, "");
    result.replace(result.find("\n"), 1, "");
    return result;
}

void Socket::send(string line) {
    const char *cstr = line.c_str();
    int transferCount = write(_acceptFd, cstr, strlen(cstr));
    if (transferCount < 0) {
        Utils::error("ERROR: writing to socket");
    }
}

