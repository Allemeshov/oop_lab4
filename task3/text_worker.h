#ifndef LAB4_TEXT_WORKER_H
#define LAB4_TEXT_WORKER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

class TextWorker {
private:
    std::vector<std::string> lines;

public:
    TextWorker(std::string file_path);
    ~TextWorker();

    void PortionUpperLowerCases();
    long GetPeriodicity(char symbol);
    double CalcSymbolProbability(char symbol);
    void SortLines();
    void SaveLinesToFile(std::string file_path);
};

#endif //LAB4_TEXT_WORKER_H
