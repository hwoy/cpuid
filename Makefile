bin=cpus
cc=gcc
as=as
CFLAGS=-O2

.PHONY: clean all

all: $(bin)

$(bin): main.o cpuid.o
	$(cc) -o $(bin) main.o cpuid.o

main.o: main.c
	$(cc) -c $(CFLAGS) main.c
cpuid: cpuid.s
	$(as) -o cpuid.o cpuid.s

clean:
	 rm -f *.o $(bin) *~

