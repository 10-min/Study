#include "dmaabc.h"
#include <cstring>

using std::cout;
using std::endl;

baseDMA::baseDMA(const char * l, int r) {
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs) {
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA() {
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs) {
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}
void baseDMA::View() const {
    cout << "상표: " << label << endl;
    cout << "등급: " << rating << endl;
}

lacksDMA::lacksDMA(const char * c, const char * l, int r) : baseDMA(l, r) {
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs) {
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const {
    baseDMA::View();
    cout << "색상: " << color << endl;
}

hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l, r) {
    style = new char[std::strlen(s) + 1];
    strcpy(style, s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) : baseDMA(rs) {
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs) {
    style = new char[std::strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs) {
    if (this == &hs)
        return *this;
    baseDMA::operator=(hs);
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return * this;
}

void hasDMA::View() const {
    baseDMA::View();
    cout << "스타일: " << style << endl;
}