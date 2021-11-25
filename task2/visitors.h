#ifndef LAB4_VISITORS_H
#define LAB4_VISITORS_H

#include <map>
#include <iostream>
#include <list>

//std::map<std::string, int> visitors;

void init_visitors(const std::list<std::string> &logins, std::map<std::string, int> visitors);

bool contains_visitor(const std::string &login, std::map<std::string, int> &visitors);

void add_visitor(const std::string &login, std::map<std::string, int> &visitors);

long process_list(const std::list<std::string> &logins, std::map<std::string, int> &visitors);

long calc_once_visited(std::map<std::string, int> &visitors);


#endif //LAB4_VISITORS_H
