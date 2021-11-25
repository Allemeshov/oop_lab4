#include "visitors.h"

void init_visitors(const std::list<std::string> &logins, std::map<std::string, int> visitors) {
    for (const auto& login : logins) {
        visitors.insert(std::pair<std::string, int>(login, 0));
    }
}

long process_list(const std::list<std::string>& logins, std::map<std::string, int>& visitors) {
    for (const auto& login : logins) {
        if (contains_visitor(login, visitors)) {
            visitors[login]++;
        } else {
            add_visitor(login, visitors);
        }
    }

    return calc_once_visited(visitors);
}

bool contains_visitor(const std::string& login, std::map<std::string, int>& visitors) {
    for(const auto& [key, value] : visitors) {
        if (key == login)
            return true;
    }

    return false;
}

void add_visitor(const std::string& login, std::map<std::string, int>& visitors) {
    visitors.insert(std::pair<std::string, int>(login, 1));
}

long calc_once_visited(std::map<std::string, int>& visitors) {
    long result = 0;
    for(const auto& [key, value] : visitors) {
        if (value == 1)
            result++;
    }

    return result;
}
