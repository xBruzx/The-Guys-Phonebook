CC = g++
CFLAGS = -wall -g

Prog2: driver.o
	$(CC) $(CFLAGS) -o driver.o
driver.o: driver.cpp 
	$(CC) $(CFLAGS) -c driver.cpp
driver.cpp: functions.o
	$(CC) $(CLFAGS) -o functions.o 
functions.o: functions.cpp LinkedList.h Contact.h
	$(CC) $(CFLAGS) -c functions.cpp
.PHONY: clean
clean:
	rm Prog2 driver.o driver.cpp functions.o