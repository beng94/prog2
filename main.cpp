#include "double.hpp"

int main(void)
{
    prec_double a("1", "4");
    prec_double b("-2", "4");

    std::cout << a++ << std::endl;
    std::cout << a  << std::endl;
    std::cout << b++ << std::endl;
    std::cout << b << std::endl;

    return 0;
}
