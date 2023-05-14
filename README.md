<picture> 
  <source media="(prefers-color-scheme: dark)" srcset="./docs/prime_logo.png">
  <img src="./docs/prime_logo.png" alt="Prime logo" height="70"> 
</picture>

# Prime: The Power of Simplicity and Complexity

Prime is an innovative programming language that seamlessly blends the simplicity of Python with the advanced and intricate features of C++ and Rust. Crafted primarily in C++, with some components implemented in C, Prime is designed to deliver a robust yet intuitive programming experience.

| **Platform** | **Architecture** | **Status** |
| ------------ | ---------------- | ---------- |
| **Windows**  | x86_64           | Underway   |
| **macOS**    | x86_64           | Upcoming   |
| **Linux**    | x86_64           | Upcoming   |
| **Phone**    | x86_64           | Upcoming   |

## Highlights and roadmap of Prime

- [x] Custom-Built Libraries
- [x] Lexer Implementation
- [x] Header Extension Support
- [x] Visual Studio Code Extension
- [ ] Parser Development (underway)
- [ ] AST - Abstract Syntax Tree (underway)
- [x] Debug Mode Configuration Settings
- [ ] LLVM Integration (in pipeline)
- [ ] Support for Writing in Different Languages within Prime (upcoming)

## Deep Dive into Prime

To learn more about Prime, our comprehensive documentation is the perfect starting point. You can access it on our GitHub page: [Prime Documentation](https://github.com/3FriendsCo/primeLang).

## Prime for Visual Studio Code

To enhance the experience of writing and debugging Prime code, we've developed a Visual Studio Code extension. You can access it here: [Prime VSCode Extension](https://github.com/3FriendsCo/Prime-Extension).

## Project Structure

| Directory  | Contents                                                                                                  |
| ---------- | --------------------------------------------------------------------------------------------------------- |
| `config/`  | here is the fiels to easily change modes etc.                                                             |
| `docs/`    | here you can find documents or other informative content.                                                 |
| `include/` | here is all of our libraries nad dependencies                                                             |
| `logs/`    | all of your logs when you execute a prime program will be added here.                                     |
| `src/`     | here you will find the core of the programming language and this includes the parser, lexer and compiler. |
| `tests/`   | here you will find the tests that is made by the development team.                                        |

## How to build the Project

Firstoff make sure that you have all prerequesities installed on your machine and that your machine supports x86_64 assembly (AMD_64). The prerequisites could be found in the file called `requirements.md` in the projects root directory. To build a Prime project, you need to run the `build.bat` file located inside `./src/build.bat`. This can be done in a terminal or command line interface. When the `build.bat` file has been ran it will build the project and then run the completed version. The completed assembly code will be created in `./src/build/generated_assembly.asm`.

## How to run the project

To run a Prime project, you need to use the `primec` command followed by the filename. This can be done in a terminal or command line interface. Here is the basic command structure:

```shell
# To run a Prime program, use the `primec` command followed by the filename
# Replace `filename` with the path to your .pri file
primec filename

# For example, if you have a file named `main.pri` in the same directory, you would type:
primec main.pri

# This command will execute your Prime program

```
