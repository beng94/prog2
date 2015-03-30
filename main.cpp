#include "double.hpp"

int main(void)
{
    prec_double a("4", "4");
    prec_double b("54", "55");

    if(b > a) std::cout<< "B is bigger\n";
    else std::cout << "B is not bigger\n";
    return 0;
}
