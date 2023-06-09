#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <chrono>

struct fruit {
    std::string name;
    int type;
};

int main() {
    std::vector<std::unique_ptr<fruit>> fruits;
    
    fruits.emplace_back(fruit{"Apple", 1});
    fruits.emplace_back(fruit{"Pear", 2});
    fruits.emplace_back(fruit{"Banana", 3});

    for(fruit& i: fruits) {
        std::cout << i.name << ":" << i.type << std::endl;
    }
    return 0;
}