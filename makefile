CC = g++
CFLAGS = -Wall -g

Prog2: driver.o functions.o
	$(CC) $(CFLAGS) -o Prog2 driver.o functions.o
driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp
functions.o: functions.cpp LinkedList.h Contact.h
	$(CC) $(CFLAGS) -c functions.cpp
.PHONY: clean
clean:
	rm *.o Prog2 driver.o  functions.o
