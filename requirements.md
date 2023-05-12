## Requirements

Assembly compiler - http://www.nasm.us/pub/nasm/releasebuilds/?C=M;O=D
CPP compiler - https://gcc.gnu.org/mirrors.html

## Install instructions:

#### Assembly compiler:

    1. Download NASM from the official site (http://www.nasm.us/pub/nasm/releasebuilds/?C=M;O=D). Download the latest version that has a name like nasm-x.xx-win64.zip where x.xx is the version number.
    2. Extract the downloaded zip file. It doesn't really matter where you put the extracted files, but you might want to put them somewhere easy to remember, like C:\Program Files\NASM.
    3. Add the NASM directory to your PATH:
        1. Search for 'Environment Variables' in your Start Menu search bar and select 'Edit the system
        environment variables'.
        2. Click on the 'Environment Variables' button.
        3. Under 'System variables', scroll down and select the variable named 'Path', then click 'Edit'.
        4. Click 'New', then 'Browse' and navigate to the directory where you extracted NASM.
        5. Click 'OK' to close all the dialogs.
    4. To confirm that NASM is installed correctly, open a new Command Prompt window and type nasm -v. You should see something like NASM version x.xx where x.xx is the version number.
