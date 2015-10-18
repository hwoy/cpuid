#ifndef NULL
#define NULL ((void *) 0)
#endif
struct _REG
{


  unsigned int eax:32;


  unsigned int ebx:32;


  unsigned int ecx:32;


  unsigned int edx:32;


};



union _EAX1_EAX
{


  struct
  {


    unsigned int step:4;


    unsigned int model:4;


    unsigned int family:4;


    unsigned int type:2;


    unsigned int _reserved1:2;


    unsigned int extmodel:4;


    unsigned int extfamily:8;


    unsigned int _reserved2:4;



  } cpu;



  unsigned int eax;



};



struct _BIT_FLAGS
{


  unsigned int bits;


  char *name;


  char *feature;


};




typedef struct _REG REG;


typedef union _EAX1_EAX EAX1_EAX;


typedef char CPUSTR[13];


typedef char CPUBANDSTR[4 * 4 * 3 + 1];



unsigned int *cpuid (REG * reg);

#ifdef _CPUID32_
int testcpuid (void);
#endif


char *getcpustr (CPUSTR str);


char *getcpubrandstr (CPUBANDSTR str);



#ifdef _CPUID_BUILTIN_VAR_

static struct _BIT_FLAGS eax1_edx[] = { {0, "fpu", "Onboard x87 FPU"},

{1, "vme", "Virtual 8086 mode extensions (such as VIF, VIP, PIV)"},

{2, "de", "Debugging extensions (CR4 bit 3)"},

{3, "pse", "Page Size Extension"},

{4, "tsc", "Time Stamp Counter"},

{5, "msr", "Model-specific registers"},

{6, "pae", "Physical Address Extension"},

{7, "mce", "Machine Check Exception"},

{8, "cx8", "CMPXCHG8 (compare-and-swap) instruction"},

{9, "apic", "Onboard Advanced Programmable Interrupt Controller"},

{10, NULL, NULL},

{11, "sep", "SYSENTER and SYSEXIT instructions"},

{12, "mtrr", "Memory Type Range Registers"},

{13, "pge", "Page Global Enable bit in CR4"},

{14, "mca", "Machine check architecture"},

{15, "cmov", "Conditional move and FCMOV instructions"},

{16, "pat", "Page Attribute Table"},

{17, "pse-36", "36-bit page size extension"},

{18, "psn", "Processor Serial Number"},

{19, "clfsh", "CLFLUSH instruction (SSE2)"},

{20, NULL, NULL},

{21, "ds", "Debug store: save trace of executed jumps"},

{22, "acpi", "Onboard thermal control MSRs for ACPI"},

{23, "mmx", "MMX instructions"},

{24, "fxsr", "FXSAVE, FXRESTOR instructions, CR4 bit 9"},

{25, "sse", "SSE instructions (a.k.a. Katmai New Instructions)"},

{26, "sse2", "SSE2 instructions"},

{27, "ss", "CPU cache supports self-snoop"},

{28, "htt", "Hyper-threading"},

{29, "tm", "Thermal monitor automatically limits temperature"},

{30, "ia64", "IA64 processor emulating x86"},

{31, "pbe", "Pending Break Enable (PBE# pin) wakeup support"}
};


static struct _BIT_FLAGS eax1_ecx[] = {
    {0, "sse3", "Prescott New Instructions-SSE3 (PNI)"},

{1, "pclmulqdq", "PCLMULQDQ support"},

{2, "dtes64", "64-bit debug store (edx bit 21)"},

{3, "monitor", "MONITOR and MWAIT instructions (SSE3)"},

{4, "ds-cpl", "CPL qualified debug store"},

{5, "vmx", "Virtual Machine eXtensions"},

{6, "smx", "Safer Mode Extensions (LaGrande)"},

{7, "est", "Enhanced SpeedStep"},

{8, "tm2", "Thermal Monitor 2"},

{9, "ssse3", "Supplemental SSE3 instructions"},

{10, "cnxt-id", "L1 Context ID"},

{11, "sdbg", "Silicon Debug interface"},

{12, "fma", "Fused multiply-add (FMA3)"},

{13, "cx16", "CMPXCHG16B instruction"},

{14, "xtpr", "Can disable sending task priority messages"},

{15, "pdcm", "Perfmon & debug capability"},

{16, NULL, NULL},

{17, "pcid", "Process context identifiers (CR4 bit 17)"},

{18, "dca", "Direct cache access for DMA writes[10][11]"},

{19, "sse4.1", "SSE4.1 instructions"},

{20, "sse4.2", "SSE4.2 instructions"},

{21, "x2apic", "x2APIC support"},

{22, "movbe", "MOVBE instruction (big-endian)"},

{23, "popcnt", "POPCNT instruction"},

{24, "tsc-deadline",
 "APIC supports one-shot operation using a TSC deadline value"},

{25,
 "aes",
 "AES instruction set"},


{26, "xsave", "XSAVE, XRESTOR, XSETBV, XGETBV"},

{27, "osxsave",
 "XSAVE enabled by OS"},


{28, "avx", "Advanced Vector Extensions"},

{29, "f16c",
 "F16C (half-precision) FP support"},


{30, "rdrnd", "RDRAND (on-chip random number generator) support"},


{31, "hypervisor",
 "Running on a hypervisor (always 0 on a real CPU, but also with some hypervisors)"}


};


static struct _BIT_FLAGS eax7ecx0_ebx[] = {
    {0, "fsgsbase", "Access to base of %fs and %gs"},

{1, "", "IA32_TSC_ADJUST"},

{2, "sgx", "Software Guard Extensions"},

{3, "bmi1", "Bit Manipulation Instruction Set 1"},

{4, "hle", "Transactional Synchronization Extensions"},

{5, "avx2", "Advanced Vector Extensions 2"},

{6, NULL, NULL},

{7, "smep", "Supervisor-Mode Execution Prevention"},

{8, "bmi2", "Bit Manipulation Instruction Set 2"},

{9, "erms", "Enhanced REP MOVSB/STOSB"},

{10, "invpcid", "INVPCID instruction"},

{11, "rtm", "Transactional Synchronization Extensions"},

{12, "pqm", "Platform Quality of Service Monitoring"},

{13, "", "FPU CS and FPU DS deprecated"},

{14, "mpx", "Intel MPX (Memory Protection Extensions)"},

{15, "pqe", "Platform Quality of Service Enforcement"},

{16, "avx512f", "AVX-512 Foundation"},

{17, "avx512dq", "AVX-512 Doubleword and Quadword Instructions"},

{18, "rdseed", "RDSEED instruction"},

{19, "adx", "Intel ADX (Multi-Precision Add-Carry Instruction Extensions)"},


{20, "smap", "Supervisor Mode Access Prevention"},

{21, "avx512ifma",
 "AVX-512 Integer Fused Multiply-Add Instructions"},


{22, "pcommit", "PCOMMIT instruction"},

{23, "clflushopt",
 "CLFLUSHOPT instruction"},


{24, "clwb", "CLWB instruction"},

{25, "", "Intel Processor Trace"},


{26, "avx512pf", "AVX-512 Prefetch Instructions"},

{27, "avx512er",
 "AVX-512 Exponential and Reciprocal Instructions"},


{28, "avx512cd", "AVX-512 Conflict Detection Instructions"},

{29,
 "sha",
 "Intel SHA extensions"},


{30, "avx512bw", "AVX-512 Byte and Word Instructions"},

{31,
 "avx512vl",
 "AVX-512 Vector Length Extensions"}


};


static struct _BIT_FLAGS eax7ecx0_ecx[] = {
    {0, "prefetchwt1", "PREFETCHWT1 instruction"},

{1, "avx512vbmi", "AVX-512 Vector Bit Manipulation Instructions"},

{2, NULL, NULL},
{3, NULL, NULL},
{4, NULL, NULL},
{5, NULL, NULL},
{6, NULL, NULL},
{7, NULL, NULL},
{8, NULL, NULL},
{9, NULL, NULL},
{10, NULL, NULL},
{11, NULL, NULL},
{12, NULL, NULL},
{13, NULL, NULL},
{14, NULL, NULL},
{15, NULL, NULL},
{16, NULL, NULL},
{17, NULL, NULL},
{18, NULL, NULL},
{19, NULL, NULL},
{20, NULL, NULL},
{21, NULL, NULL},
{22, NULL, NULL},
{23, NULL, NULL},
{24, NULL, NULL},
{25, NULL, NULL},
{26, NULL, NULL},
{27, NULL, NULL},
{28, NULL, NULL},
{29, NULL, NULL},
{30, NULL, NULL},
{31, NULL, NULL},

};


static struct _BIT_FLAGS eax80000001h_edx[] = { {0, "fpu", "Onboard x87 FPU"},

{1, "vme", "Virtual mode extensions (VIF)"},

{2, "de", "Debugging extensions (CR4 bit 3)"},

{3, "pse", "Page Size Extension"},

{4, "tsc", "Time Stamp Counter"},

{5, "msr", "Model-specific registers"},

{6, "pae", "Physical Address Extension"},

{7, "mce", "Machine Check Exception"},

{8, "cx8", "CMPXCHG8 (compare-and-swap) instruction"},

{9, "apic", "Onboard Advanced Programmable Interrupt Controller"},

{10, NULL, NULL},

{11, "syscall", "YSCALL and SYSRET instructions"},

{12, "mtrr", "Memory Type Range Registers"},

{13, "pge", "Page Global Enable bit in CR4"},

{14, "mca", "Machine check architecture"},

{15, "cmov", "Conditional move and FCMOV instructions"},

{16, "pat", "Page Attribute Table"},

{17, "pse36", "36-bit page size extension"},

{18, NULL, NULL},

{19, "mp", "Multiprocessor Capable"},

{20, "nx", "NX bit"},

{21, NULL, NULL},

{22, "mmxext", "Extended MMX"},

{23, "mmx", "MMX instructions"},

{24, "fxsr", "FXSAVE, FXRSTOR instructions, CR4 bit 9"},

{25, "fxsr_opt", "FXSAVE/FXRSTOR optimizations"},

{26, "pdpe1gb", "Gibibyte pages"},

{27, "rdtscp", "RDTSCP instruction"},

{28, NULL, NULL},

{29, "lm", "Long mode"},

{30, "3dnowext", "Extended 3DNow!"},

{31, "3dnow", "3DNow!"}

};



static struct _BIT_FLAGS eax80000001h_ecx[] = {
    {0, "lahf_lm", "LAHF/SAHF in long mode"},

{1, "cmp_legacy", "Hyperthreading not valid"},

{2, "svm", "Secure Virtual Machine"},

{3, "extapic", "Extended APIC space"},

{4, "cr8_legacy", "CR8 in 32-bit mode"},

{5, "abm", "Advanced bit manipulation (lzcnt and popcnt)"},

{6, "sse4a", "SSE4a"},

{7, "misalignsse", "Misaligned SSE mode"},

{8, "3dnowprefetch", "PREFETCH and PREFETCHW instructions"},

{9, "osvw", "OS Visible Workaround"},

{10, "ibs", "Instruction Based Sampling"},

{11, "xop", "XOP instruction set"},

{12, "skinit", "SKINIT/STGI instructions"},

{13, "wdt", "Watchdog timer"},

{14, NULL, NULL},

{15, "lwp", "Light Weight Profiling[21]"},

{16, "fma4", "4 operands fused multiply-add"},

{17, "tce", "Translation Cache Extension"},

{18, NULL, NULL},

{19, "nodeid_msr", "NodeID MSR"},

{20, NULL, NULL},

{21, "tbm", "Trailing Bit Manipulation"},

{22, "topoext", "Topology Extensions"},

{23, "perfctr_core", "Core performance counter extensions"},

{24, "perfctr_nb", "NB performance counter extensions"},

{25, NULL, NULL},

{26, "dbx", "Data breakpoint extensions"},

{27, "perftsc", "Performance TSC"},

{28, "pcx_l2i", "L2I perf counter extensions"},

{29, NULL, NULL},
{30, NULL, NULL},
{31, NULL, NULL}


};



#endif
