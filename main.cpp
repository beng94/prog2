#include "double.hpp"

int main(void)
{

    prec_double a("12", "5");
    prec_double b("5", "12");

    std::cout << a << std::endl;

    prec_double c = a + b;
    std::cout << (a + b) << std::endl;

    return 0;
}
