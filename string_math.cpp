#include "string_math.hpp"

static void equalize_length(std::string& a, std::string& b)
{
    int len_a = a.length();
    int len_b = b.length();

    while(len_a < len_b) { a = "0" + a; len_a++;}
    while(len_b < len_a) { b = "0" + b; len_b++;}
}

int char_to_int (const char c) { return c - '0';}
char int_to_char(const int i) { return '0' + i;}

std::string n_chars (char c, int n)
{
    std::string out = "";
    for(int i = 0; i<n; i++) out += c;

    return out;
}

std::string add (const std::string& a, const std::string& b)
{
    std::string tmp_a = a;
    std::string tmp_b = b;

    std::string out = "";

    equalize_length(tmp_a, tmp_b);

    int carry = 0;
    int len = tmp_a.length();
    for(int i = len-1; i >= 0; i--)
    {
        int sum = char_to_int(tmp_a[i]) + char_to_int(tmp_b[i]) + carry;
        out = std::to_string(sum % 10) + out;
        carry = sum / 10;
    }

    if(carry != 0) out = std::to_string(carry) + out;

    return out;
}

std::string sub (const std::string& a, const std::string& b)
{
    //TODO: check whether a > b, if yes, exit
    //TODO: implement negative numbers, watch out for borrowing
    //TODO: Do I really have to copy these?

    std::string tmp_a = a;
    std::string tmp_b = b;

    equalize_length(tmp_a, tmp_b);

    std::string out = "";

    for(int i = tmp_b.length()-1; i>= 0; i--)
    {
        if(char_to_int(tmp_b[i]) > char_to_int(tmp_a[i]))
        {
            //Have to boorow
            for(int j = i-1; j >= 0; j--)
            {
                if(char_to_int(tmp_a[j]) != 0)
                {
                    tmp_a[j] = int_to_char(char_to_int(tmp_a[j]) -1);
                    break;
                }
            }
            out = std::to_string((10 + char_to_int(tmp_a[i])) - char_to_int(tmp_b[i]))  + out;
        }
        else
        {
            out = std::to_string(char_to_int(tmp_a[i]) - char_to_int(tmp_b[i])) + out;
        }

        if(tmp_b[i] == '0') break;
    }

    return out;
}

static std::string multiply_digit (const std::string& a, const char b)
{
    std::string out = "";
    int carry = 0;
    for(int i = a.length()-1; i >= 0; i--)
    {
        int mult = char_to_int(b) * char_to_int(a[i]) + carry;
        out = std::to_string(mult % 10) + out;
        carry = mult / 10;
    }

    if(carry != 0) out = std::to_string(carry) + out;

    return out;
}

std::string multiply (const std::string& a, const std::string& b)
{
    if(a == "0" || b == "0") return "0";

    std::string tmp_a = a;
    std::string tmp_b = b;

    int len_b = b.length();

    std::string out = "";

    for(int i = 0; i < len_b; i++)
    {
        std::string tmp = multiply_digit(tmp_a, tmp_b[i]);
        tmp += n_chars('0', len_b -i -1);
        out = add(out, tmp);
    }

    return out;
}

bool equal (const std::string& a, const std::string& b)
{
    int len = a.length();
    int i = 0;
    while(i < len && a[i] == b[i]) i++;

    if(i == len) return true;
    return false;
}

bool smaller(const std::string& a, const std::string& b)
{
    int len = a.length();
    int i = 0;

    if(equal(a, b)) return false;
    else
    {
        while(i < len && a[i] == b[i]) i++;

        if(char_to_int(a[i]) < char_to_int(b[i])) return true;
        else return false;
    }

    return false;
}

bool bigger (const std::string& a, const std::string& b)
{
    int len = a.length();
    int i = 0;

    if(equal(a, b)) return false;
    else
    {
        while(i < len && a[i] == b[i]) i++;

        if(a[i] > b[i]) return true;
        else return false;
    }
    return false;
}
