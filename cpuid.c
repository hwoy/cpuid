#include "cpuid.h"

REG *cpuid (REG * reg)
{
	__asm__ volatile("cpuid":"=a"(reg->eax),"=b"(reg->ebx),"=c"(reg->ecx),"=d"(reg->edx):"a"(reg->eax),"b"(reg->ebx),"c"(reg->ecx),"d"(reg->edx));
	return reg;
}

#ifndef __x86_64__
int testcpuid (void)
{
  int ret;
  __asm__ volatile( "pushfl\n\t"
                    "pushfl\n\t"
                    "xorl $0x00200000,(%%esp)\n\t"
                    "popfl\n\t"
                    "pushfl\n\t"
                    "popl %%eax\n\t"
                    "xorl (%%esp),%%eax\n\t"
                    "popfl\n\t"
                    "andl $0x00200000,%%eax"
                    :"=a"(ret)
  );

  return ret;
}
#endif