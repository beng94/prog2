#include "string_math.hpp"
#include "double.hpp"

prec_double::prec_double(const string& num,
                         const string& denom)
{
    if(!valid_num(num) || !valid_num(denom)) throw "invalid input";
    neg = get_neg(num, denom);
    this->num = remove_neg(num);
    this->denom = remove_neg(denom);
}

prec_double prec_double::operator+ (const prec_double& b)
{
    string tmp_denom = multiply(this->denom, b.denom);
    string tmp_num;

    if(this->neg == false && b.neg == false) //++
    {
        tmp_num = add(multiply(this->num, b.denom), multiply(this->denom, b.num));
    }

    else if(this->neg == true && b.neg == true) //--
    {
        tmp_num = add(multiply(this->num, b.denom), multiply(this->denom, b.num));
        tmp_num = '-' + tmp_num;
    }

    else if(this->neg == true && b.neg == false) //-+
    {
        if(equal(multiply(this->num, b.denom),
                 multiply(this->denom,  b.num))) tmp_num = "0";

        else if(bigger(multiply(this->num, b.denom),
                       multiply(this->denom, b.num)))
        {
            tmp_num = sub(multiply(this->num, b.denom),
                          multiply(this->denom, b.num));
            tmp_num = '-' + tmp_num;
        }
        else if(smaller(multiply(this->num, b.denom),
                        multiply(this->denom, b.num)))
        {
            tmp_num = sub(multiply(this->denom, b.num),
                          multiply(this->num, b.denom));
        }
    }

    else if(this->neg == false && b.neg == true) //+-
    {
        if(equal(multiply(this->num, b.denom),
                 multiply(this->denom,  b.num))) tmp_num = "0";

        else if(bigger(multiply(this->num, b.denom),
                       multiply(this->denom, b.num))) //+ > -
        {
            tmp_num = sub(multiply(this->num, b.denom),
                          multiply(this->denom, b.num));
        }
        else if(smaller(multiply(this->num, b.denom),
                        multiply(this->denom, b.num))) //+ < -
        {
            tmp_num = sub(multiply(this->denom, b.num),
                          multiply(this->num, b.denom));
            tmp_num = '-' + tmp_num;
        }
    }

    return prec_double(tmp_num, tmp_denom);
}

prec_double prec_double::operator- (const prec_double& b)
{
    string tmp_num =  "";
    string tmp_denom = multiply(this->denom, b.denom);

    if(this->neg == false && b.neg == false) //++
    {
        if(equal(multiply(this->num, b.denom),
                 multiply(this->denom,  b.num))) tmp_num = "0";

        else if(bigger(multiply(this->num, b.denom),
                       multiply(this->denom, b.num)))
        {
             tmp_num = sub(multiply(this->num, b.denom),
                           multiply(this->denom, b.num));
        }
        else if(smaller(multiply(this->num, b.denom),
                       multiply(this->denom, b.num)))
        {
            tmp_num = sub(multiply(this->denom,  b.num),
                          multiply(this->num, b.denom));
            tmp_num = '-' + tmp_num;
        }
    }
    else if(this->neg == true && b.neg == true) //--
    {
        if(equal(multiply(this->num, b.denom),
                 multiply(this->denom,  b.num))) tmp_num = "0";

        else if(bigger(multiply(this->num, b.denom),
                       multiply(this->denom, b.num)))
        {
            tmp_num = sub(multiply(this->num, b.denom),
                          multiply(this->denom, b.num));
            tmp_num = '-' + tmp_num;
        }
        else if(smaller(multiply(this->num, b.denom),
                       multiply(this->denom, b.num)))
        {
            tmp_num = sub(multiply(this->denom, b.num),
                          multiply(this->num, b.denom));
        }
    }
    else if(this->neg == true && b.neg == false)
    {
        tmp_num = add(multiply(this->num, b.denom),
                      multiply(this->denom, b.num));
        tmp_num = '-' + tmp_num;
    }
    else if(this->neg == false && b.neg == true)
    {
        tmp_num = add(multiply(this->num, b.denom),
                      multiply(this->denom, b.num));
    }

    return prec_double(tmp_num, tmp_denom);
}

prec_double prec_double::operator* (const prec_double& b)
{
    string tmp_num = multiply(this->num, b.num);
    string tmp_denom = multiply(this->denom, b.denom);

    if((this->neg == true && b.neg == false) ||
       (this->neg == false && b.neg == true)) tmp_num = '-' + tmp_num;

    return prec_double(tmp_num, tmp_denom);
}


prec_double prec_double::operator/ (const prec_double& b)
{
    string tmp_num = multiply(this->num, b.denom);
    string tmp_denom = multiply(this->denom, b.num);

    if((this->neg == true && b.neg == false) ||
       (this->neg == false && b.neg == true)) tmp_num = '-' + tmp_num;

    return prec_double(tmp_num, tmp_denom);
}

//TODO implement negative numbers
prec_double prec_double::operator++ (int)
{
    //num = add(num, denom);
    prec_double tmp = *this;
    *this = *this + prec_double(this->denom, this->denom);

    return tmp;
}

//TODO: implement negative numbers
prec_double prec_double::operator++()
{
    prec_double tmp(num, denom);
    ++(*this);

    return tmp;
}

//TODO: implement negative numbers
bool prec_double::operator< (const prec_double& b) const
{
    string tmp_a_num = multiply(this->num, b.denom);
    string tmp_b_num = multiply(this->denom, b.num);

    if(tmp_a_num.length() < tmp_b_num.length()) return true;
    if(tmp_a_num.length() > tmp_b_num.length()) return false;
    else if(smaller(tmp_a_num, tmp_b_num)) return true;

    return false;
}

//TODO: implement negative numbers
bool prec_double::operator> (const prec_double& b) const
{
    string tmp_a_num = multiply(this->num, b.denom);
    string tmp_b_num = multiply(this->denom, b.num);

    if(tmp_a_num.length() < tmp_b_num.length()) return true;
    if(tmp_a_num.length() > tmp_b_num.length()) return false;
    else if(bigger(tmp_a_num, tmp_b_num)) return true;

    return false;
}

//TODO: implement negative number
bool prec_double::operator== (const prec_double& b) const
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
    if(rhs.neg)
    {
        os << " " << rhs.num << std::endl;
        os << "-" << n_chars('-', std::max(rhs.num.length(), rhs.denom.length())) << std::endl;
        os << " " << rhs.denom << std::endl;
    }
    else
    {
    os << rhs.num << std::endl;
    os << n_chars('-', std::max(rhs.num.length(), rhs.denom.length())) << std::endl;
    os << rhs.denom << std::endl;
    }

    return os;
}

