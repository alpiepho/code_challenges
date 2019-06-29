CC  = g++
CFLAGS  = -I. -Wall
CFLAGS  +=  -DDEBUG

all: samplerd

samplerd: main.o utils.o datastore.o socket.o process.o launcher.o
	$(CC) -lpthread -o $@ $^
	chmod 700 samplerd

utils.o: utils.cpp
	$(CC) -c $(CFLAGS) $<

datastore.o: datastore.cpp
	$(CC) -c $(CFLAGS) $<

socket.o: socket.cpp
	$(CC) -c $(CFLAGS) $<

process.o: process.cpp
	$(CC) -c $(CFLAGS) $<

launcher.o: launcher.cpp
	$(CC) -c $(CFLAGS) $<

main.o: main.cpp
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f samplerd
	rm -f *.o
