bin=cpus
cc=gcc
as=as
CFLAGS=-O2

.PHONY: clean all

all: $(bin)

$(bin): main.o cpuid.o excpuid.o
	$(cc) -o $(bin) main.o cpuid.o excpuid.o

main.o: main.c
	$(cc) -c $(CFLAGS) -D_CPUID_BUILTIN_VAR_ main.c
cpuid: cpuid.s
	$(as) -o cpuid.o cpuid.s
excpuid.o: excpuid.c
	$(cc) -c $(CFLAGS) excpuid.c

clean:
	 rm -f *.o $(bin) *~

