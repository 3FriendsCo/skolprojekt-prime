@echo off
nasm -f win64 generated_assembly.asm -o generated_assembly.obj
gcc generated_assembly.obj -o generated_assembly.exe
generated_assembly.exe
