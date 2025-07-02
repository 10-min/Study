#include <cstring>
#include <cctype>
#include "string2.h"
using std::cout;
using std::cin;

int String::num_strings = 0;

int String::HowMany() {
    return num_strings;
}

String::String(const char * s) {
    len = std::strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String() {
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & st) {
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
}

String::~String() {
    --num_strings;
    delete [] str;
}

void String::stringlow() {
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}

void String::stringup()
{
    for (int i = 0; i < len; i++)
    {
        if (islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
}

int String::has(char ch) const {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ch)
            count++;
    }

    return count;
}

String & String::operator=(const String & st) {
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}

String & String::operator=(const char * s) {
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char & String::operator[](int i) {
    return str[i];
}

const char & String::operator[](int i) const {
    return str[i];
}

String String::operator+(const String & st) const {
    String result;
    int total = len + st.len;
    result.str = new char[total + 1];
    strcpy(result.str, str);
    strcpy(result.str + len, st.str);
    result.len = total;
    return result;
}

String String::operator+(const char * s) const
{
    return *this + String(s);
}

bool operator<(const String & st1, const String & st2) {
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String & st1, const String & st2) {
    return st2 < st1;
}

bool operator==(const String & st1, const String & st2) {
    return (strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st) {
    os << st.str;
    return os;
}

istream & operator>>(istream & is, String & st) {
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

String operator+(const char * s, const String & st) {
    return String(s) + st;
}