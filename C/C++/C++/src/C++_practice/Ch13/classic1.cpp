#include <iostream>
#include <cstring>
#include "classic1.h"

using std::cout;
using std::endl;

Cd::Cd(const char * s1, const char * s2, int n, double x) {
    performers = new char[strlen(s1) + 1];
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d) {
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() {
    performers = new char[1];
    performers[0] = '\0';
    label = new char[1];
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd() {
    delete [] performers;
    delete [] label;
}

void Cd::Report() const {
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "수록 곡 수: " << selections << endl;
    cout << "연주 시간: " << playtime << endl; 
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d)
        return *this;
    delete[] performers;
    delete[] label;
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char * s, const char * s1, const char * s2, int n, double x) 
        : Cd(s1, s2, n, x) 
{
    song = new char[strlen(s) + 1];
    strcpy(song, s);
}

Classic::Classic(const char * s, const Cd & d) : Cd(d) {
    song = new char[strlen(s) + 1];
    strcpy(song, s);
}

Classic::Classic() : Cd() {
    song = new char[1];
    song[0] = '\0';
}

Classic::~Classic() {
    delete [] song;
}

void Classic::Report() const
{
    Cd::Report();
    cout << "대표곡: " << song << endl;
}

Classic &Classic::operator=(const Classic &c)
{
    if (this == &c)
        return *this;

    Cd::operator=(c);
    delete [] song;
    song = new char[strlen(c.song) + 1];
    strcpy(song, c.song);

    return *this;
}