bin=cpuid

CC=gcc
CFLAGS=-O2 -std=c90 -pedantic -Wall

.PHONY: clean all

all: $(bin)

$(bin): main.o cpuid.o excpuid.o
	$(CC) -o $(bin) main.o cpuid.o excpuid.o

clean:
	 rm -f *.o $(bin) *~ *.exe

