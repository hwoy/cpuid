#define REGNUM 4
enum __REG__
{
  EAX, EBX, ECX, EDX
};

unsigned int *cpuid (unsigned int mode, unsigned int *reg);
