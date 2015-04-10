#include "string.hpp"

string::string()
{
    len = 0;
    str = NULL;
}

string::string(const char* rhs)
{
    len = strlen(rhs);
    str = new char[len + 1];
    strcpy(str, rhs);
    str[len] = '\0';
}

string::string(const string& rhs)
{
    len = rhs.len;
    str = new char[len + 1];
    strcpy(str, rhs.str);
    str[len] = '\0';
}

string::~string()
{
    delete [] str;
}

int string::length() const{ return len; }

string string::substring(int start, int end) const
{
    if(start < 0) start = 0;
    if(end > this->length()-1) end = this->length()-1;

    char* new_str = new char[end-start + 2];
    strncpy(new_str, str + start, end-start+1);
    new_str[end-start+1] = '\0';
    string out(new_str);
    delete [] new_str;

    return out;
}

string& string::operator= (const string& rhs)
{
    if(this != &rhs)
    {
        len = rhs.len;
        delete [] str;
        str = new char[len + 1];
        strcpy(str, rhs.str);
        str[len] = '\0';
    }

    return *this;
}

string string::operator+(string& rhs)
{
    char* tmp = new  char [len + rhs.len + 1];
    strcpy(tmp, str);
    strcpy(tmp + len, rhs.str);
    tmp[len + rhs.len + 1] = '\0';
    string out(tmp);
    delete[] tmp;

    return out;
}

string string::operator+(char c)
{
    int tmp_len = len + 2;
    char* tmp = new char[tmp_len];
    strcpy(tmp, str);
    tmp[tmp_len-2] = c;
    tmp[tmp_len-1] = '\0';
    string out(tmp);
    delete [] tmp;

    return out;
}

char& string::operator[](int id) const{ return str[id]; }

string operator+(char c, string& rhs)
{
    int tmp_len = rhs.len + 2;
    char* tmp = new char[tmp_len];
    tmp[0] = c;
    strcpy(tmp + 1, rhs.str);
    tmp[tmp_len -1] = '\0';
    string out(tmp);
    delete [] tmp;

    return out;
}

bool string::operator==(const char* rhs) const
{
    bool out = (strcmp(str, rhs) == 0);
    return out;
}

std::ostream& operator<< (std::ostream& os, const string& rhs)
{
    os << rhs.str;

    return os;
}
