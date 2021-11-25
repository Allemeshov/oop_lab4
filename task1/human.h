#ifndef LAB4_HUMAN_H
#define LAB4_HUMAN_H

#include <iostream>
#include <utility>

enum Sex {
    Male,
    Female,
    X
};

std::string sex_to_str(Sex s) {
    switch (s) {
        case Male:
            return "Male";
        case Female:
            return "Female";
        case X:
            return "X";
    }
}

class Human {
private:
    std::string _name;
    long _age;
    Sex _sex;

public:
    std::string get_name() {
        return _name;
    }

    long get_age() {
        return _age;
    }

    Sex get_sex() {
        return _sex;
    }


    Human(std::string name, long age, Sex sex) {
        _name = std::move(name);
        _age = age;
        _sex = sex;
    }

    ~Human() {
        _name.clear();
    }

    static void Print(const Human &human) {
        std::cout << "I'm a human:" << std::endl
                  << '\t' << "My name is " << human._name << std::endl
                  << '\t' << "I'm " << human._age << " y.o." << std::endl
                  << '\t' << "And I'm " << sex_to_str(human._sex) << std::endl;
    }
};

#endif //LAB4_HUMAN_H
