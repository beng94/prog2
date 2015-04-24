#include "test.hpp"

void test_init()
{
    try
    {
        prec_double a("-1", "-2");
        prec_double b("-1", "2");
        prec_double c("1", "-2");
        prec_double d("1", "2");
    }
    catch(const string str)
        { std::cout << str << std::endl; }

    try { prec_double a("a", "1"); }
    catch (const string str)
        { std::cout << str << std::endl; }

    try {prec_double a("1-", "1"); }
    catch (const string str)
        { std::cout << str << std::endl; }
}

void test_print()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}

void test_add()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << a + a << std::endl;
    std::cout << a + b << std::endl;
    std::cout << a + c << std::endl;
    std::cout << a + d << std::endl;
}

void test_sub()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << a - a << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a - c << std::endl;
    std::cout << a - d << std::endl;
}

void test_mult()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << a * a << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a * c << std::endl;
    std::cout << a * d << std::endl;
}

void test_div()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << a / a << std::endl;
    std::cout << a / b << std::endl;
    std::cout << a / c << std::endl;
    std::cout << a / d << std::endl;
}

void test_preinc()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << ++a  << std::endl;
    std::cout << ++b << std::endl;
    std::cout << ++c << std::endl;
    std::cout << ++d << std::endl;
}

void test_postinc()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << a++  << std::endl;
    std::cout << b++ << std::endl;
    std::cout << c++ << std::endl;
    std::cout << d++ << std::endl;
}

void test_small()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << (a > a) << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << (a > c) << std::endl;
    std::cout << (a > d) << std::endl;
}

void test_big()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << (a < a) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a < c) << std::endl;
    std::cout << (a < d) << std::endl;
}

void test_equal()
{
    prec_double a("-1", "-2");
    prec_double b("-1", "2");
    prec_double c("1", "-2");
    prec_double d("1", "2");

    std::cout << (a == a) << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a == c) << std::endl;
    std::cout << (a == d) << std::endl;
}
