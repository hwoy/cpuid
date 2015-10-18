.text

#ifdef _CPUID_LIN32_
.globl cpuid
.globl testcpuid
cpuid:
pushl %ebp
movl %esp,%ebp
subl $8,%esp

pushl %ebx
pushl %edi

movl 8(%ebp),%edi


movl 0(%edi),%eax
movl 4(%edi),%ebx
movl 8(%edi),%ecx
movl 12(%edi),%edx


cpuid

movl 8(%ebp),%edi


movl %eax,(%edi)
movl %ebx,4(%edi)
movl %ecx,8(%edi)
movl %edx,12(%edi)

movl %edi,%eax

popl %edi
popl %ebx
leave
ret

testcpuid:
    pushfl 
    pushfl 
    xorl $0x00200000,(%esp)
    popfl 
    pushfl
    popl %eax 
    xorl (%esp),%eax
    popfl
    andl $0x00200000,%eax
    ret

#else


.globl cpuid

cpuid:
pushq %rbp
movq %rsp,%rbp
subq $16,%rsp

pushq %rbx

movq %rdi,-8(%rbp)

movl (%rdi),%eax
movl 4(%rdi),%ebx
movl 8(%rdi),%ecx
movl 12(%rdi),%edx

cpuid

movq -8(%rbp),%rdi


movl %eax,(%rdi)
movl %ebx,4(%rdi)
movl %ecx,8(%rdi)
movl %edx,12(%rdi)

movq %rdi,%rax

popq %rbx
leave
ret

#endif
