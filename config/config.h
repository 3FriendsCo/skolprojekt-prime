#pragma once
#include <string>

namespace prime_settings {
  bool debug_mode = false; // AJAJAJ compiler_core kommer skrika utan "debug_mode = false/true;"
  std::string branch = ""; // stable, development
  std::string mode = ""; // debug, execute, compile, etc.
  std::string license_key = ""; // prime_abc123@!
  std::string version = "23.4";
}

namespace config {
    void update() {
      
    }

    void overwrite(std::string input) {
      std::ofstream overwriter;
      std::ifstream scanner;
      overwriter.open("config.h"); // Change "ate" to correct editing mode
      scanner.open("config.h");
      std::string strReplace = "morning";
      std::string strTemp;
      while(scanner >> strTemp) {
        if(strTemp == strReplace){
          strTemp = input;
        }
        strTemp += "\n";
        overwriter << strTemp;
      }
    }
}

// config::overwrite("debug");