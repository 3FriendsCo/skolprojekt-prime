#pragma once
#include <iostream>

namespace bas {
    inline void log() {

    }

    inline void logf() {
        
    }

    inline void log_error() {
        
    }

    inline void read() {
        
    }

    inline void readf() {
        
    }

    inline void read_error() {
        
    }

    inline void flush() {
        
    }

    class file {
        public:
        enum mode {
            READ,
            WRITE,
            NOTE
        };

        file(const char* file_of_intrest, int mode) {
            #include <fstream>

            switch(mode) {
                case READ:
                // std::ifstream filestreamOBJname;
                    
                break;
                case WRITE:

                break;
            }
        }

        ~file() {
            //Provide runtime flag?
        }
    };

    /*

    bas::file infile("Code.pri", READ);
    bas::file outfile("Code.pri", WRITE);
    bas::file File("Code.pri", NOTE);
    
    */
}

// There is a built-in namespace with that name, you are currently overwriting it, do you want to overwrite it?