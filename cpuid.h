
struct _REG
{
	unsigned int eax:32;
	unsigned int ebx:32;
	unsigned int ecx:32;
	unsigned int edx:32;
};

unsigned int *cpuid (unsigned int mode, struct _REG *reg)
