#include "string.hpp"

string to_string(int c);
string add (const string& a, const string& b);
string sub (const string& a, const string& b);
string multiply (const string& a, const string& b);
string n_chars (char c, int n);
bool smaller (const string& a, const string& b);
bool bigger (const string& a, const string& b);
bool equal (const string& a, const string& b);
bool valid_num(const string& str);
bool get_neg(const string& num, const string& denom);
string remove_neg(const string& str);
