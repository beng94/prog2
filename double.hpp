#include <string>
#include <iostream>

class prec_double
{
    private:
        std::string num; //szamlalo
        std::string denom; //nevezo
    public:
        prec_double(const std::string& a, const std::string& b);

        std::string& operator+ (prec_double& b);
        std::string& operator- (prec_double& b);
        std::string& operator* (prec_double& b);
        std::string& operator/ (prec_double& b);
};
