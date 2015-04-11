#include "string_math.hpp"

static void equalize_length(string& a, string& b)
{
    int len_a = a.length();
    int len_b = b.length();

    while(len_a < len_b) { a = '0' + a; len_a++;}
    while(len_b < len_a) { b = '0' + b; len_b++;}
}

string to_string(int c)
{
    string out("");

    do
    {
        int rem = c % 10;
        char let = rem + '0';
        out = let + out;
        c /= 10;
    }
    while(c != 0);

    return out;
}

int char_to_int (const char c) { return c - '0';}
char int_to_char(const int i) { return '0' + i;}

string n_chars (char c, int n)
{
    string out("");
    for(int i = 0; i<n; i++) out = out + c;

    return out;
}

string add (const string& a, const string& b)
{
    string tmp_a = a;
    string tmp_b = b;

    string out = "";

    equalize_length(tmp_a, tmp_b);

    int carry = 0;
    int len = tmp_a.length();
    for(int i = len-1; i >= 0; i--)
    {
        int sum = char_to_int(tmp_a[i]) + char_to_int(tmp_b[i]) + carry;
        out = to_string(sum % 10) + out;
        carry = sum / 10;
    }

    if(carry != 0) out = to_string(carry) + out;

    return out;
}

string sub (const string& a, const string& b)
{
    //TODO: check whether a > b, if yes, exit
    //TODO: implement negative numbers, watch out for borrowing
    //TODO: Do I really have to copy these?

    string tmp_a = a;
    string tmp_b = b;

    equalize_length(tmp_a, tmp_b);

    string out = "";

    for(int i = tmp_b.length()-1; i>= 0; i--)
    {
        if(char_to_int(tmp_b[i]) > char_to_int(tmp_a[i]))
        {
            //Have to borrow
            for(int j = i-1; j >= 0; j--)
            {
                if(char_to_int(tmp_a[j]) != 0)
                {
                    tmp_a[j] = int_to_char(char_to_int(tmp_a[j]) -1);
                    break;
                }
            }
            out = to_string((10 + char_to_int(tmp_a[i])) - char_to_int(tmp_b[i]))  + out;
        }
        else
        {
            out = to_string(char_to_int(tmp_a[i]) - char_to_int(tmp_b[i])) + out;
        }

        if(tmp_b[i] == '0') break;
    }

    return out;
}

static string multiply_digit (const string& a, const char b)
{
    string out = "";
    int carry = 0;
    for(int i = a.length()-1; i >= 0; i--)
    {
        int mult = char_to_int(b) * char_to_int(a[i]) + carry;
        out = to_string(mult % 10) + out;
        carry = mult / 10;
    }

    if(carry != 0) out = to_string(carry) + out;

    return out;
}

string multiply (const string& a, const string& b)
{
    if(a == "0" || b == "0") return "0";

    string tmp_a = a;
    string tmp_b = b;

    int len_b = b.length();

    string out = "";

    for(int i = 0; i < len_b; i++)
    {
        string tmp = multiply_digit(tmp_a, tmp_b[i]);
        string cat = n_chars('0', len_b -i -1);
        tmp = tmp + cat;
        out = add(out, tmp);
    }

    return out;
}

bool equal (const string& a, const string& b)
{
    int len = a.length();
    if(len != b.length()) return false;
    int i = 0;
    while(i < len && a[i] == b[i]) i++;

    if(i == len) return true;
    return false;
}

bool smaller(const string& a, const string& b)
{
    int len = a.length();
    int i = 0;

    if(len < b.length()) return true;
    if(len > b.length()) return false;

    if(equal(a, b)) return false;
    else
    {
        while(i < len && a[i] == b[i]) i++;

        if(char_to_int(a[i]) < char_to_int(b[i])) return true;
        else return false;
    }

    return false;
}

bool bigger (const string& a, const string& b)
{
    int len = a.length();
    int i = 0;

    if(len > b.length()) return true;
    if(len < b.length()) return false;

    if(equal(a, b)) return false;
    else
    {
        while(i < len && a[i] == b[i]) i++;

        if(a[i] > b[i]) return true;
        else return false;
    }
    return false;
}

bool valid_num(const string& str)
{
    if(str[0] != '-' && (str[0] < '0' || str[0] > '9')) return false;
    for(int i = 1; i<str.length(); i++)
    {
        if(str[i] < '0' || str[i] > '9') return false;
    }

    return true;
}

bool get_neg(const string& num, const string& denom)
{
    if(num[0] == '-' && denom[0] == '-') return false;
    if((num[0] == '-' && denom[0] != '-')||
      (num[0] != '-' && denom[0] == '-')) return true;

    return false;
}

string remove_neg (const string& str)
{
    if(str[0] == '-') return str.substring(1, str.length());

    return str;
}
