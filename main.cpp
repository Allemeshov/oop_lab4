#include <iostream>
#include <list>
#include "task1/student.h"
#include "task1/human.h"
#include "task2/visitors.h"
#include "task3/text_worker.h"

void task1() {
    auto h = new Human("Sasha", 19, Male);
    Human::Print(*h);

    std::cout << std::endl;

    auto s1 = new Student("Sasha", 19, Male, "20PRI", "Software Engineering");
    Student::Print(*s1);

    std::cout << std::endl;

    auto s2 = new Student(*h, "20PRI", "Software Engineering");
    Student::Print(*s2);

    std::cout << std::endl;
}

void task2() {
    std::map<std::string, int> visitors;

    std::list<std::string> my_list{
            "12dcdwd1@dwdw.de",
            "qwerty@gmail.com",
            "qwerty@gmail.com",
            "adaawd@ddkwaod.ru",
            "12dcdwd1@dwdw.de",
            "moopa@goggle.com",
            "moopa@goggle.com",
            "lol@yandex.ru",
            "123@dwdw.ru",
            "once@visited.ru", // once visited
            "lol@yandex.ru",
            "adaawd@ddkwaod.ru",
            "adaawd@ddkwaod.ru",
            "123@dwdw.ru",
    };

    init_visitors(my_list, visitors);
    std::cout << "Once visited site number is " << process_list(my_list, visitors) << std::endl;
}

/*
 * Вывести время выполнения для каждой из функций.
 * Текст получать из файла.
 * Текст может состоять из произвольного количества строк.
 * Дан текст.
 * Определите процентное отношение строчных и прописных букв к общему числу символов в нем.
 * Определить, как часто встречается определенный символ в строке.
 * Определить вероятность появления символа в тексте.
 * Отсортировать массив строк по алфавиту. Учитывать только первый символ каждой строки
 * */
void task3() {
    auto tw = new TextWorker("input.txt");
    tw->PortionUpperLowerCases();

    std::cout << "Enter the symbol, periodicity of which to get: ";
    char symbol;
    symbol = (char) std::getchar();
    std::cout << "This symbol repeats " << tw->GetPeriodicity(symbol) << " times." << std::endl;

    std::cout << "The probability of appearing this symbol: " << tw->CalcSymbolProbability(symbol) << "%" << std::endl;

    tw->SortLines();
    tw->SaveLinesToFile("output.txt");
}

int main() {
//    task1();

//    task2();

    task3();

    return 0;
}
