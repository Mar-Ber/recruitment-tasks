#include "string_support.hpp"

std::string trim(const std::string &s)
{
    auto it_begin = s.begin();
    auto it_end = s.end();
    while (it_begin != it_end && std::isspace(*it_begin)) it_begin++;
    while (it_end-it_begin > 0 && std::isspace(*(it_end-1))) it_end--;
    std::string new_str = std::string(it_begin, it_end);
    return new_str;
}

char* trim(char s [])
{
    while(std::isspace(*s)) s++;
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}