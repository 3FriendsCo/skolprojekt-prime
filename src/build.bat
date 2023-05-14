@echo off
SETLOCAL EnableDelayedExpansion

echo COMPILING "main.cpp"...
g++ -O3 ./main.cpp -o ./build/main.exe
IF %ERRORLEVEL% NEQ 0 (
    echo COMPILATION FAILED. #NOT PASSED ^(ERROR^)
    exit /b %ERRORLEVEL%
) ELSE (
    echo COMPILED "main.cpp" SUCCESSFULLY. #PASSED
)

echo EXECUTING "main.exe"...
"./build/main.exe"
IF %ERRORLEVEL% NEQ 0 (
    echo EXECUTION OF "main.exe" FAILED. #NOT PASSED ^(ERROR^)
    exit /b %ERRORLEVEL%
) ELSE (
    echo "main.exe" EXECUTED SUCCESSFULLY. #PASSED
)

echo ASSEMBLING "generated_assembly.asm"...
fasm ./build/generated_assembly.asm ./build/generated_assembly.exe
IF %ERRORLEVEL% NEQ 0 (
    echo ASSEMBLING FAILED. #NOT PASSED ^(ERROR^)
    exit /b %ERRORLEVEL%
) ELSE (
    echo ASSEMBLED "generated_assembly.asm" SUCCESSFULLY. #PASSED
)

echo EXECUTING "generated_assembly.exe"...
"./build/generated_assembly.exe"
IF %ERRORLEVEL% NEQ 0 (
    echo EXECUTION OF "generated_assembly.exe" FAILED. #NOT PASSED ^(ERROR^)
    exit /b %ERRORLEVEL%
) ELSE (
    echo "generated_assembly.exe" EXECUTED SUCCESSFULLY. #PASSED
)
