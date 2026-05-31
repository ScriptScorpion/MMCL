bits 64
global _start

divide:
    push rax
    push rdx
    mov rax, r14
    mov rdx, 0
    idiv r15
    
    mov r14, rax ; Quotient in r14
    mov r15, rdx ; Remainder in r15
    
    pop rdx
    pop rax
    ret

_start:
    mov rax, 10
    mov rcx, 5
    
    mov r14, rax ; who we divide
    mov r15, rcx ; by who we divide
    call divide
 
    mov rdi, r14 ; get result

    mov rax, 60
    syscall

