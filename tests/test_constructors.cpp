#include <iostream>
#include <string>

class fruit {
    std::string kind;
    int sweetness;
    public:
    fruit(std::string the_kind = "Unknown") {
        kind == the_kind;
        if(kind == "Apple") sweetness == 6;
    }
};

int main() {
    fruit apple("Apple");
}