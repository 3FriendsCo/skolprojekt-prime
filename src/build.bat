:: @echo off
:: g++ -O3 ./main.cpp -o ./build/main.exe
:: "./build/main.exe"

:: nasm -f win64 ./build/generated_assembly.asm -o ./build/generated_assembly.o
::gcc ./build/generated_assembly.o -o ./build/generated_assembly.exe
:: "./build/generated_assembly.exe"

:: ---------------------------

@echo off
g++ -O3 ./main.cpp -o ./build/main.exe
"./build/main.exe"

fasm ./build/generated_assembly.asm ./build/generated_assembly.exe
"./build/generated_assembly.exe"
