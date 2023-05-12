BITS 32
global  _start
section .text
    _start:     
        mov       rax, 4
        mov       rbx, 1
        mov       rcx, message
        mov       rdx, message_len
        mov       rsi, 0
        xor       r8, r8
        syscall
        
        mov       eax, 1
        xor       ebx, ebx
        syscall
section   .data
    message:    db    "Hello, World!", 10
    message_len: equ   $ - message