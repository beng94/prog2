#include "string.hpp"
#include <iostream>

int main(void)
{
    string a("alma");
    string b("");

    b = '!' + b;
    std::cout << b << std::endl;

    return 0;
}
