#include <stdio.h>
#include "cpuid.h"

int
main (void)
{
  struct _REG reg;
  char str[13];
  unsigned int i;

  cpuid (0, &reg);

  ((unsigned int *)str)[0] = reg.ebx;;

  ((unsigned int *)str)[1] = reg.edx;

  ((unsigned int *)str)[2] = reg.ecx;


  printf ("\nYour CPU string = %s\n", str);

  return 0;


