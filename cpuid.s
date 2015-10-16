.text
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

