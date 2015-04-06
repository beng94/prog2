#include "string_math.hpp"
#include "double.hpp"

prec_double::prec_double(const string& num,
                         const string& denom)
{
    if(!valid_num(num))
    {std::cout << "num\n";}
    if(!valid_num(denom)) std::cout << "denom\n";
    neg = get_neg(num, denom);
    this->num = remove_neg(num);
    this->denom = remove_neg(denom);
}

prec_double prec_double::operator+ (const prec_double& b)
{
    string tmp_num = add(multiply(this->num, b.denom), multiply(this->denom, b.num));
    string tmp_denom = multiply(this->denom, b.denom);

    return prec_double(tmp_num, tmp_denom);
}

prec_double prec_double::operator- (const prec_double& b)
{
    string tmp_num = sub(multiply(this->num, b.denom), multiply(this->denom, b.num));
    string tmp_denom = multiply(this->denom, b.denom);

    return prec_double(tmp_num, tmp_denom);
}

prec_double prec_double::operator* (const prec_double& b)
{
    string tmp_num = multiply(this->num, b.num);
    string tmp_denom = multiply(this->denom, b.denom);

    return prec_double(tmp_num, tmp_denom);
}


prec_double prec_double::operator/ (const prec_double& b)
{
    string tmp_num = multiply(this->num, b.denom);
    string tmp_denom = multiply(this->denom, b.num);

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

bool prec_double::operator< (const prec_double& b)
{
    string tmp_a_num = multiply(this->num, b.denom);
    string tmp_b_num = multiply(this->denom, b.num);

    if(tmp_a_num.length() < tmp_b_num.length()) return true;
    if(tmp_a_num.length() > tmp_b_num.length()) return false;
    else if(smaller(tmp_a_num, tmp_b_num)) return true;

    return false;
}

bool prec_double::operator> (const prec_double& b)
{
    string tmp_a_num = multiply(this->num, b.denom);
    string tmp_b_num = multiply(this->denom, b.num);

    if(tmp_a_num.length() < tmp_b_num.length()) return true;
    if(tmp_a_num.length() > tmp_b_num.length()) return false;
    else if(bigger(tmp_a_num, tmp_b_num)) return true;

    return false;
}

bool prec_double::operator== (const prec_double& b)
{
    string tmp_a_num = multiply(this->num, b.denom);
    string tmp_b_num = multiply(this->denom, b.num);

    if(tmp_a_num.length() == tmp_b_num.length())
    {
        if(equal(tmp_a_num, tmp_b_num)) return true;
        else return false;

    }

    return false;
}

std::ostream& operator<< (std::ostream& os, const prec_double& rhs)
{
    os << rhs.num << std::endl;
    os << n_chars('-', std::max(rhs.num.length(), rhs.denom.length())) << std::endl;
    os << rhs.denom << std::endl;

    return os;
}

