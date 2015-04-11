#include "double.hpp"

int main(void)
{
    prec_double a("-2", "4");
    prec_double b("-2", "4");

    std::cout << (a==b) << std::endl;

    return 0;
}
