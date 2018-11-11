# cpuid
1. This cpuid is very simple and portable cpuid(x86 and x86-64).
2. Written in ansi C.
3. Should be compiled by gcc.

### Example

```
****************** CPU ******************
CPU string:GenuineIntel
CPU Brand string:Intel(R) Core(TM) i3-2120 CPU @ 3.30GHz
step:7
model:A
family:6
type:0
extmodel:2A
extfamily:6

****************** EAX=1,EDX ******************
bit 0:fpu [Onboard x87 FPU]
bit 1:vme [Virtual 8086 mode extensions (such as VIF, VIP, PIV)]
bit 2:de [Debugging extensions (CR4 bit 3)]
bit 3:pse [Page Size Extension]
bit 4:tsc [Time Stamp Counter]
bit 5:msr [Model-specific registers]
bit 6:pae [Physical Address Extension]
bit 7:mce [Machine Check Exception]
bit 8:cx8 [CMPXCHG8 (compare-and-swap) instruction]
bit 9:apic [Onboard Advanced Programmable Interrupt Controller]
bit 11:sep [SYSENTER and SYSEXIT instructions]
bit 12:mtrr [Memory Type Range Registers]
bit 13:pge [Page Global Enable bit in CR4]
bit 14:mca [Machine check architecture]
bit 15:cmov [Conditional move and FCMOV instructions]
bit 16:pat [Page Attribute Table]
bit 17:pse-36 [36-bit page size extension]
bit 19:clfsh [CLFLUSH instruction (SSE2)]
bit 21:ds [Debug store: save trace of executed jumps]
bit 22:acpi [Onboard thermal control MSRs for ACPI]
bit 23:mmx [MMX instructions]
bit 24:fxsr [FXSAVE, FXRESTOR instructions, CR4 bit 9]
bit 25:sse [SSE instructions (a.k.a. Katmai New Instructions)]
bit 26:sse2 [SSE2 instructions]
bit 27:ss [CPU cache supports self-snoop]
bit 28:htt [Hyper-threading]
bit 29:tm [Thermal monitor automatically limits temperature]
bit 31:pbe [Pending Break Enable (PBE# pin) wakeup support]

****************** EAX=1,ECX ******************
bit 0:sse3 [Prescott New Instructions-SSE3 (PNI)]
bit 1:pclmulqdq [PCLMULQDQ support]
bit 2:dtes64 [64-bit debug store (edx bit 21)]
bit 3:monitor [MONITOR and MWAIT instructions (SSE3)]
bit 4:ds-cpl [CPL qualified debug store]
bit 5:vmx [Virtual Machine eXtensions]
bit 7:est [Enhanced SpeedStep]
bit 8:tm2 [Thermal Monitor 2]
bit 9:ssse3 [Supplemental SSE3 instructions]
bit 13:cx16 [CMPXCHG16B instruction]
bit 14:xtpr [Can disable sending task priority messages]
bit 15:pdcm [Perfmon & debug capability]
bit 17:pcid [Process context identifiers (CR4 bit 17)]
bit 19:sse4.1 [SSE4.1 instructions]
bit 20:sse4.2 [SSE4.2 instructions]
bit 23:popcnt [POPCNT instruction]
bit 24:tsc-deadline [APIC supports one-shot operation using a TSC deadline value]
bit 26:xsave [XSAVE, XRESTOR, XSETBV, XGETBV]
bit 27:osxsave [XSAVE enabled by OS]
bit 28:avx [Advanced Vector Extensions]

****************** EAX=7,ECX=0,EBX ******************

****************** EAX=7,ECX=0,ECX ******************

****************** EAX=80000001h,EDX ******************
bit 11:syscall [YSCALL and SYSRET instructions]
bit 20:nx [NX bit]
bit 27:rdtscp [RDTSCP instruction]
bit 29:lm [Long mode]

****************** EAX=80000001h,ECX ******************
bit 0:lahf_lm [LAHF/SAHF in long mode]

```


### Contact me. 
- Web: https://github.com/hwoy 
- Email: zaintcorp@yahoo.com 
- Facebook: http://www.facebook.com/dead-root 
