#include <stdio.h>
#include "cpuid.h"
 static void showflags (unsigned int reg, struct _BIT_FLAGS *flag);
 int 
main (void) 
{
   REG reg;
   CPUSTR str;
   CPUBANDSTR bstr;
   EAX1_EAX eax1_eax;
   unsigned int i;
     puts ("****************** CPU ******************");
   printf ("CPU string = %s\n", getcpustr (str));
    reg.eax = 0x80000000;
   cpuid (&reg);
   if (reg.eax >= 0x80000004)
     
    {
       printf ("CPU Brand string = %s\n", getcpubrandstr (bstr));
     }
    putchar ('\n');
    reg.eax = 1;
   cpuid (&reg);
   eax1_eax.eax = reg.eax;
    printf ("step:%X\n", eax1_eax.cpu.step);
   printf ("model:%X\n", eax1_eax.cpu.model);
   printf ("family:%X\n", eax1_eax.cpu.family);
   printf ("type:%X\n", eax1_eax.cpu.type);
    if (eax1_eax.cpu.family == 0xF)
     
    {
       printf ("extmodel:%X\n",
		 (eax1_eax.cpu.extmodel << 4) + eax1_eax.cpu.model);
       printf ("extfamily:%X\n",
		 eax1_eax.cpu.extfamily + eax1_eax.cpu.family);
     }
   
  else if (eax1_eax.cpu.family == 0x6)
     
    {
       printf ("extmodel:%X\n", 
		 (eax1_eax.cpu.extmodel << 4) + eax1_eax.cpu.model);
       printf ("extfamily:%X\n", eax1_eax.cpu.family);
     }
    putchar ('\n');
      puts ("****************** EAX=1,EDX ******************");
   showflags (reg.edx, eax1_edx);
   putchar ('\n');
     puts ("****************** EAX=1,ECX ******************");
   showflags (reg.ecx, eax1_ecx);
   putchar ('\n');
      reg.eax = 7;
   reg.ecx = 0;
   cpuid (&reg);
    puts ("****************** EAX=7,ECX=0,EBX ******************");
   showflags (reg.ebx, eax7ecx0_ebx);
   putchar ('\n');
     puts ("****************** EAX=7,ECX=0,ECX ******************");
   showflags (reg.ecx, eax7ecx0_ecx);
   putchar ('\n');
     reg.eax = 0x80000000;
   cpuid (&reg);
    if (reg.eax > 0x80000000)
     
    {
        reg.eax = 0x80000001;
       cpuid (&reg);
        puts ("****************** EAX=80000001h,EDX ******************");
       showflags (reg.edx, eax80000001h_edx);
       putchar ('\n');
        puts ("****************** EAX=80000001h,ECX ******************");
       showflags (reg.ecx, eax80000001h_ecx);
       putchar ('\n');
      }
     return 0;
 }

 static void
showflags (unsigned int reg, struct _BIT_FLAGS *flag) 
{
  unsigned int i;
   for (i = 0; i < 32; i++)
     
    {
       if (reg & (1 << i))
	 
	{
	   if (flag[i].name)
	    printf ("%bit %u:%s [%s]\n", i, flag[i].name, flag[i].feature);
	 }
     }
 }

  
