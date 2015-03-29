#include "double.hpp"
#include "string_math.hpp"
#include <iostream>

int main(void)
{
    std::string a = "120";
    std::string b = "40";

    std::cout << multiply(a, b) << std::endl;
    std::cout << multiply("0", a) << std::endl;
    std::cout << multiply(a, "0") << std::endl;
    std::cout << multiply("99", "99") << std::endl;

    return 0;
}
