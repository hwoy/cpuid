#include <stdio.h>
#include "cpuid.h"

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
      
printf ("extmodel:%X\n", (eax1_eax.cpu.extmodel << 4) + eax1_eax.cpu.model);
      
printf ("extfamily:%X\n", eax1_eax.cpu.extfamily+eax1_eax.cpu.family);
    
}
  
  else if (eax1_eax.cpu.family == 0x6)
    
    {
      
printf ("extmodel:%X\n",
	       (eax1_eax.cpu.extmodel << 4) + eax1_eax.cpu.model);
      
printf ("extfamily:%X\n", eax1_eax.cpu.family);
    
}
  
 
putchar ('\n');
  
 
puts ("****************** EAX=0,EDX ******************");
  
for (i = 0; i < 32; i++)
    
    {
      
if (reg.edx & (1 << i))
	
	{
	  
if (eax1_edx[i].name)
	    printf ("%bit %u:%s [%s]\n", i, eax1_edx[i].name,
		    eax1_edx[i].feature);
	
}
    
}
  
putchar ('\n');
  
 
puts ("****************** EAX=0,ECX ******************");
  
for (i = 0; i < 32; i++)
    
    {
      
if (reg.ecx & (1 << i))
	
	{
	  
if (eax1_ecx[i].name)
	    printf ("%bit %u:%s [%s]\n", i, eax1_ecx[i].name,
		    eax1_ecx[i].feature);
	
}
    
}
  
putchar ('\n');
  
 
reg.eax = 7;
  
reg.ecx = 0;
  
cpuid (&reg);
  
 
puts ("****************** EAX=7,ECX=0,EBX ******************");
  
for (i = 0; i < 32; i++)
    
    {
      
if (reg.ebx & (1 << i))
	
	{
	  
if (eax7ecx0_ebx[i].name)
	    printf ("%bit %u:%s [%s]\n", i, eax7ecx0_ebx[i].name,
		    eax7ecx0_ebx[i].feature);
	
}
    
}
  
putchar ('\n');
  
 
puts ("****************** EAX=7,ECX=0,ECX ******************");
  
for (i = 0; i < 32; i++)
    
    {
      
if (reg.ecx & (1 << i))
	
	{
	  
if (eax7ecx0_ecx[i].name)
	    printf ("%bit %u:%s [%s]\n", i, eax7ecx0_ecx[i].name,
		    eax7ecx0_ecx[i].feature);
	
}
    
}
  
putchar ('\n');
  
 
reg.eax = 0x80000000;
  
cpuid (&reg);
  
 
if (reg.eax > 0x80000000)
    
    {
      
 
reg.eax = 0x80000001;
      
cpuid (&reg);
      
 
puts ("****************** EAX=80000001h,EDX ******************");
      
for (i = 0; i < 32; i++)
	
	{
	  
if (reg.edx & (1 << i))
	    
	    {
	      
if (EAX80000001h_edx[i].name)
		printf ("%bit %u:%s [%s]\n", i, EAX80000001h_edx[i].name,
			EAX80000001h_edx[i].feature);
	    
}
	
}
      
putchar ('\n');
      
 
puts ("****************** EAX=80000001h,ECX ******************");
      
for (i = 0; i < 32; i++)
	
	{
	  
if (reg.ecx & (1 << i))
	    
	    {
	      
if (EAX80000001h_ecx[i].name)
		printf ("%bit %u:%s [%s]\n", i, EAX80000001h_ecx[i].name,
			EAX80000001h_ecx[i].feature);
	    
}
	
}
      
putchar ('\n');
    
 
}
  
 
 
return 0;

}


