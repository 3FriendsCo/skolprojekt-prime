liberate interface;

class human {
    int height;
};

class hero extends human: public {

};

fn circumference(int dia): static {
    double pi = 1.1415926535;
    double rand = dia*pi;
    return rand;
}

main() {
    log(circumference(123));
    log("Prime is gigachad! :p")
}