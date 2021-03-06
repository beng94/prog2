#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>

class string
{
private:
    char* str;
    int len;
public:
    string();
    string(const char* str);
    string(const string& s);
    ~string();
    int length() const;
    string substring(int start, int end) const;

    string& operator= (const string& rhs);
    char& operator[](int id) const;
    string operator+(const string& rhs) const;
    string operator+(char c);
    bool operator==(const char* rhs) const;
    friend string operator+(char c, string& rhs);
    friend string operator+(const char* str, const string& rhs);
    friend std::ostream& operator<< (std::ostream& os, const string& rhs);
};

#endif
