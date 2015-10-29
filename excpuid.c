#include "cpuid.h"
char *
getcpustr (CPUSTR str)
{
  REG reg;
  reg.eax = 0;

  cpuid (&reg);

  ((REG32 *) str)[0] = reg.ebx;;

  ((REG32 *) str)[1] = reg.edx;

  ((REG32 *) str)[2] = reg.ecx;

  str[3 * sizeof (REG32)] = 0;
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
      ((REG32 *) str)[j++] = reg.eax;
      ((REG32 *) str)[j++] = reg.ebx;
      ((REG32 *) str)[j++] = reg.ecx;
      ((REG32 *) str)[j++] = reg.edx;
    }

  str[j * sizeof (REG32)] = 0;

  return str;

}