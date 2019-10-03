#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector < std::string > SplitIntoWords(const std::string &s) {
    std::vector < std::string > result;

    auto start = s.begin();
    auto finish = std::find(start, s.end(), ' ');
    while (finish != s.end()) {
        result.push_back(std::string(start, finish));
        start = ++finish;
        finish = std::find(start, s.end(), ' ');
    }

    result.push_back(std::string(start, finish));

    return result;
}

