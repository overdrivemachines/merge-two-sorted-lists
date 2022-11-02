
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

merge-two-sorted-lists: merge-two-sorted-lists.o
	$(CC) $(CFLAGS) -o merge-two-sorted-lists merge-two-sorted-lists.o

merge-two-sorted-lists.o: merge-two-sorted-lists.cpp
	$(CC) $(CFLAGS) -c merge-two-sorted-lists.cpp

clean:
	rm -rf merge-two-sorted-lists merge-two-sorted-lists.o
