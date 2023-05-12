; ---------------------------------------------------------------------------
; Assembly version: x86_64 (AMD_64)
; 
; Copyright (c) 2023, 3FriendsCo
; Authors: Pontus Henriksson & Neo Mannskär
; 
; Licensed under the MIT License. You may not use this file except in compliance
; with the License. You may obtain a copy of the License at
; 
;     https://opensource.org/licenses/MIT
; 
; ---------------------------------------------------------------------------
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

