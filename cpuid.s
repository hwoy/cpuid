.text
.globl cpuid

cpuid:
pushq %rbp
movq %rsp,%rbp
subq $16,%rsp

pushq %rbx

movq %rsi,-8(%rbp)

movl %edi,%eax
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

