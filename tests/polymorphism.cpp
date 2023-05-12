#include <iostream>
#include <vector>

class Base {
public:
    virtual void print() {
        std::cout << "I am a Base object" << std::endl;
    }
};

class Derived1 : public Base {
public:
    void print() {
        std::cout << "I am a Derived1 object" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void print() {
        std::cout << "I am a Derived2 object" << std::endl;
    }
};

int main() {
    std::vector<Base*> objects;
    objects.emplace_back(new Derived1());
    objects.emplace_back(new Derived2());

    for (auto obj : objects) {
        obj->print();
    }

    // Clean up memory allocated for objects
    for (auto obj : objects) {
        delete obj;
    }

    return 0;
}
