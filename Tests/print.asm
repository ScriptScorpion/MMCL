bits 64
global _start
_start:
    mov rax, 200
    mov r15, rax
    call print_num
    
    mov rax, 60
    xor rdi, rdi
    syscall

print_num:
    ; in 'div' instruction
    ; rax - controls high 8 bits of the number(9-16 bits)
    ; rdx - controls low 8 bits of the number(1-8 bits)
    push rax
    push rdi
    push rsi
    push rdx

    mov r14, 10
    xor r13, r13
    xor r12, r12
    mov rax, r15
    .det_size:
        xor rdx, rdx
        div r14
        test rax, rax
        jz .loop_prepare
        inc r13 ; doing index instead of regular position btw
        jmp .det_size
    
    .loop_prepare:
        mov rax, r15
    
    .loop:
        cmp r12, r13
        ja .clean ; not jae because if register value will be 0 - which is number too, so if we put 'jae' it doesn't even print it cuz index 0 size 0 
        xor rdx, rdx
        div r14
        inc r12
        add rdx, '0'
        push rdx
        jmp .loop

    .clean:
        test r12, r12
        jz .end
        
        mov rax, 1
        mov rdi, 1
        mov rsi, rsp
        mov rdx, 1
        syscall
        
        dec r12
        pop r14
        jmp .clean

    .end:
        pop rdx
        pop rsi
        pop rdi
        pop rax

        ret
