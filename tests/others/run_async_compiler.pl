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

my $compile_command = 'g++ -o C:\Users\neo.mannskar\Documents\Compilers\skolprojekt-prime\async_compiler_core.exe C:\Users\neo.mannskar\Documents\Compilers\skolprojekt-prime\async_compiler_core.cpp';
my $run_command = 'C:\Users\neo.mannskar\Documents\Compilers\skolprojekt-prime\async_compiler_core.exe';
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