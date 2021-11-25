#ifndef LAB4_STUDENT_H
#define LAB4_STUDENT_H

#include "human.h"

class Student : Human {
private:
    std::string _group;
    std::string _program;

public:
    std::string get_group() {
        return _group;
    }

    std::string get_program() {
        return _program;
    }

    Student(std::string name, long age, Sex sex, std::string group, std::string program) : Human(name, age, sex) {
        _group = std::move(group);
        _program = std::move(program);
    }
    Student(const Human& human, std::string group, std::string program) : Human(human) {
        _group = std::move(group);
        _program = std::move(program);
    }

    ~Student() {
        _group.clear();
        _program.clear();
    }

    static void Print(Student &student) {
        std::cout << "I'm a student:" << std::endl
                  << '\t' << "My name is " << student.get_name() << std::endl
                  << '\t' << "I'm " << student.get_age() << " y.o." << std::endl
                  << '\t' << "And I'm " << sex_to_str(student.get_sex()) << std::endl
                  << '\t' << "I study at " << student.get_group() << " group" << std::endl
                  << '\t' << "I learn " << student.get_program() << std::endl;
    }
};

#endif //LAB4_STUDENT_H
