#include "string.hpp"
#include <iostream>

//TODO: implement negative numbers

class prec_double
{
    private:
        string num; //szamlalo
        string denom; //nevezo
    public:
        prec_double(const string& a, const string& b);

        prec_double operator+ (const prec_double& b);
        prec_double operator- (const prec_double& b);
        prec_double operator* (const prec_double& b);
        prec_double operator/ (const prec_double& b);
        prec_double operator++ (int);
        prec_double operator++ ();
        bool operator< (const prec_double& b);
        bool operator> (const prec_double& b);
        bool operator== (const prec_double& b);

        friend std::ostream& operator<< (std::ostream& os, const prec_double& rhs);
};
