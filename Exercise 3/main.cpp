#include "string_support.hpp"

int main()
{
    char s1 [] = "\n\t Hi World   ";
    std::string s2 = "\n\r   Hello World\n";

    std::cout << "before: " << R"(")" << s1 << R"(")" << std::endl;
    std::cout << "after: " << R"(")" << trim(s1) << R"(")" << std::endl;
    //std::cout << "Type: " << typeid(s1).name() << std::endl;
    //std::cout << "Type: " << typeid(trim(s1)).name() << std::endl;

    std::cout << "before: " << R"(")" << s2 << R"(")" << std::endl;
    std::cout << "after: " << R"(")" << trim(s2) << R"(")" << std::endl;
    //std::cout << "Type: " << typeid(s2).name() << std::endl;
    //std::cout << "Type: " << typeid(trim(s2)).name() << std::endl;

    return 0;
}