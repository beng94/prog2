#include "double.hpp"

int main(void)
{
    prec_double a("12", "5");
    prec_double b("5", "12");

    prec_double c = a-b;
    std::cout << c << std::endl;
    return 0;
}
