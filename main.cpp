#include "double.hpp"

int main(void)
{
    prec_double a("-1", "-2");
    prec_double b("4", "4");

    std::cout << (a*b) << std::endl;
    std::cout << (a/b) << std::endl;

    return 0;
}
