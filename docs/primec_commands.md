# Compilation and Editing Instructions

## Compilation:

```cpp
- prime "file"
- exe "file"
- cpp "file"
```

## Editing

```cpp
- prime: -m debug
-        -m exec
-        -lk "prime_123abc"
-        -b "stable"
-        -b "development"
-        -v prime24

```

# Code snippets

## Basic structure:

```cpp
seize;
force debug_mode;
liberate interface;

main() {
    log("Hello World!");
    return 0;
}

```

## Namespace prime_settings:

```cpp
namespace prime_settings {
  bool debug_mode = false;
  std::string branch = "";
  std::string license_key = ""; 
}

```

## Terminal:

```shell
prime: -dm true
```

## Compiler.cpp:

```cpp
ofstream overwrite;
overwrite.open("config.h");
prime_settings::debug_mode = true;
overwrite.close("config.h");
```

## Prime_settings.h:

```cpp
namespace prime_settings {
  bool debug_mode = true;
  std::string branch = "";
  std::string license_key = ""; 
}
```