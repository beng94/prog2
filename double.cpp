#include "double.hpp"
#include "string_math.hpp"

prec_double::prec_double(const std::string& num,
                         const std::string& denom) :
                        num(num),
                        denom(denom) {}

prec_double prec_double::operator+ (prec_double& b)
{
    std::string tmp_num = add(multiply(this->num, b.denom), multiply(this->denom, b.num));
    std::string tmp_denom = multiply(this->denom, b.denom);

    return prec_double(tmp_num, tmp_denom);
}

prec_double prec_double::operator- (prec_double& b)
{
    std::string tmp_num = sub(multiply(this->num, b.denom), multiply(this->denom, b.num));
    std::string tmp_denom = multiply(this->denom, b.denom);

    return prec_double(tmp_num, tmp_denom);
}

prec_double prec_double::operator* (prec_double& b)
{
    std::string tmp_num = multiply(this->num, b.num);
    std::string tmp_denom = multiply(this->denom, b.denom);

    return prec_double(tmp_num, tmp_denom);
}


prec_double prec_double::operator/ (prec_double& b)
{
    std::string tmp_num = multiply(this->num, b.denom);
    std::string tmp_denom = multiply(this->denom, b.num);

    return prec_double(tmp_num, tmp_denom);
}

prec_double prec_double::operator++ (int)
{
    num = add(num, denom);

    return *this;
}

prec_double prec_double::operator++()
{
    prec_double tmp(num, denom);
    ++(*this);

    return tmp;
}

std::ostream& operator<< (std::ostream& os, prec_double& rhs)
{
    os << rhs.num << std::endl;
    os << n_chars('-', std::max(rhs.num.length(), rhs.denom.length())) << std::endl;
    os << rhs.denom << std::endl;

    return os;
}

