#include "cpuid.h"
char *
getcpustr (CPUSTR str)
{
  REG reg;
  reg.eax = 0;

  cpuid (&reg);

  ((unsigned int *) str)[0] = reg.ebx;;

  ((unsigned int *) str)[1] = reg.edx;

  ((unsigned int *) str)[2] = reg.ecx;

  str[3 * sizeof (unsigned int)] = 0;
  return str;
}

char *
getcpubrandstr (CPUBANDSTR str)
{
  REG reg;
  unsigned int i, j;

  for (i = 0x80000002, j = 0; i <= 0x80000004; i++)
    {
      reg.eax = i;
      cpuid (&reg);
      ((unsigned int *) str)[j++] = reg.eax;
      ((unsigned int *) str)[j++] = reg.ebx;
      ((unsigned int *) str)[j++] = reg.ecx;
      ((unsigned int *) str)[j++] = reg.edx;
    }

  str[j * sizeof (unsigned int)] = 0;

  return str;
}
