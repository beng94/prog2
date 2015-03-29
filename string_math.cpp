#include "string_math.hpp"

static void equalize_length(std::string& a, std::string& b)
{
    int len_a = a.length();
    int len_b = b.length();

    while(len_a < len_b) { a = "0" + a; len_a++;}
    while(len_b < len_a) { b = "0" + b; len_b++;}
}

int char_to_int (const char c) { return c - '0';}

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

