#!/usr/bin/perl

use strict;
use warnings;

sub clear_console {
    if ($^O =~ /MSWin32/) {  # Windows
        system("cls");
    } else {  # Unix/Linux/macOS
        system("clear");
    }
}

# -------------------- [ NOTES ] --------------------
# Currently this speed_test program is only set up to be ran on a file called compiler_core.cpp and on Neo's laptop. Make this script dynamic to work on every machine later.
# Maybe it could be better if this script runs the build.bat file instead for a more insighful check instead as that will also compile the program and run the assembly afterwards.
# -------------------- [ NOTES ] --------------------

my $compile_command = 'g++ -o C:\Users\neo.mannskar\Documents\Compilers\skolprojekt-prime\compiler_core.exe C:\Users\neo.mannskar\Documents\Compilers\skolprojekt-prime\compiler_core.cpp';
my $run_command = 'C:\Users\neo.mannskar\Documents\Compilers\skolprojekt-prime\compiler_core.exe';
my $times = 50;

# Clear the console
clear_console();

# Compile the code
system($compile_command);

# Run the compiled executable 50 times
for (my $i = 1; $i <= $times; $i++) {
    print "Run #$i:\n";
    system($run_command);
    print "\n";
}