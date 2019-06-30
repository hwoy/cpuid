#ifndef __CPUID_H__
#define __CPUID_H__

#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef unsigned int REG32;
struct _REG
{

  REG32 eax:32;

  REG32 ebx:32;

  REG32 ecx:32;

  REG32 edx:32;

};

union _EAX1_EAX
{

  struct
  {

    REG32 step:4;

    REG32 model:4;

    REG32 family:4;

    REG32 type:2;

    REG32 _reserved1:2;

    REG32 extmodel:4;

    REG32 extfamily:8;

    REG32 _reserved2:4;

  } cpu;

  REG32 eax;

};


struct _BIT_FLAGS
{

  REG32 bits;

  char *name;

  char *feature;

};


typedef struct _REG REG;


typedef union _EAX1_EAX EAX1_EAX;


typedef char CPUSTR[13];


typedef char CPUBANDSTR[4 * 4 * 3 + 1];


REG cpuid (REG * reg);

#ifndef __x86_64__
int testcpuid (void);
#endif


char *getcpustr (CPUSTR str);


char *getcpubrandstr (CPUBANDSTR str);


#endif
