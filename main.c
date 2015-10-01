#include <stdio.h>
#include "cpuid.h"

int
main (void)
{

  unsigned int reg[4];
  char str[13];

  cpuid (0, reg);
  *((unsigned int *) str + 0) = reg[EBX];
  *((unsigned int *) str + 1) = reg[EDX];
  *((unsigned int *) str + 2) = reg[ECX];

  str[12] = 0;

  printf ("Your CPU string = %s\n", str);
  return 0;

}
