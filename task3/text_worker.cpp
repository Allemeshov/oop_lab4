#include "text_worker.h"

TextWorker::TextWorker(std::string file_path) {
    std::ifstream file(file_path);
    std::string temp;
    if (file.is_open()) {
        while (std::getline(file, temp)) {
            lines.push_back(temp);
        }
    }
}

TextWorker::~TextWorker() {
    lines.clear();
}

void TextWorker::PortionUpperLowerCases() {
    int uppers = 0;
    int lowers = 0;
    int all = 0;

    for (const auto& line : lines) {
        for (const char& symbol : line) {
            if (65 <= symbol && symbol <= 90)
                uppers++;
            else if (97 <= symbol && symbol <= 122)
                lowers++;

            all++;
        }
    }

    double uppers_per = round(uppers * 100 / all);
    double lowers_per = round(lowers * 100 / all);
    std::cout << "Uppers percentage: " << uppers_per << "%" << std::endl;
    std::cout << "Lowers percentage: " << lowers_per << "%" << std::endl;
}

long TextWorker::GetPeriodicity(char searching_symbol) {
    long periodicity = 0;
    for (const auto& line : lines) {
        for (const char& symbol : line) {
            if (symbol == searching_symbol)
                periodicity++;
        }
    }

    return periodicity;
}

double TextWorker::CalcSymbolProbability(char searching_symbol) {
    long periodicity = 0;
    long all = 0;
    for (const auto& line : lines) {
        for (const char& symbol : line) {
            if (symbol == searching_symbol)
                periodicity++;

            all++;
        }
    }

    return round(periodicity * 100 / all);
}

void TextWorker::SortLines() {
    std::sort(lines.begin(), lines.end(), [](std::string& a, std::string& b){ return a[0] < b[0]; });
}

void TextWorker::SaveLinesToFile(std::string file_path) {
    std::ofstream file(file_path, std::ios::trunc);

    for (const auto& line : lines) {
        file << line;
        file << std::endl;
    }
}
