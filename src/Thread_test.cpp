#include <iostream>
#include <thread>

class MyClass {
public:
  MyClass(int value) : value_(value) {
    std::cout << "Constructor called with value " << value_ << std::endl;
  }

  ~MyClass() {
    std::cout << "Destructor called with value " << value_ << std::endl;
  }

private:
  int value_;
};

class Hej {
public:
    Hej(int value) : value_(value) {
    std::cout << "Hej Constructor called with value " << value_ << std::endl;
  }

    ~Hej() {
    std::cout << "Hej Destructor called with value " << value_ << std::endl;
  }

private:
  int value_;
};

int main() {
  std::thread t1([]() { MyClass obj(1); });
  std::thread t2([]() { Hej obj(2); });

  t1.join();
  t2.join();

  return 0;
}
