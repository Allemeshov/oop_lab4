#include <iostream>
#include "student.h"
#include "human.h"

int main() {

    auto h = new Human("Sasha", 19, Male);
    Human::Print(*h);

    std::cout << std::endl;

    auto s1 = new Student("Sasha", 19, Male, "20PRI", "Software Engineering");
    Student::Print(*s1);

    std::cout << std::endl;

    auto s2 = new Student(*h, "20PRI", "Software Engineering");
    Student::Print(*s2);

    std::cout << std::endl;

    return 0;
}
