#include <iostream>
#include <cstring>
#include "classic.h"

using std::cout;
using std::endl;

Cd::Cd(const char * s1, const char * s2, int n, double x) {
    strncpy(performers, s1, 49);
    performers[49] = '\0';
    strncpy(label, s2, 19);
    label[19] = '\0';
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d) {
    strncpy(performers, d.performers, 49);
    performers[49] = '\0';
    strncpy(label, d.label, 19);
    label[19] = '\0';
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() {
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd() {}

void Cd::Report() const {
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "수록 곡 수: " << selections << endl;
    cout << "연주 시간: " << playtime << endl; 
}

Cd & Cd::operator=(const Cd & d) {
    if (this == &d)
        return *this;

    strncpy(performers, d.performers, 49);
    performers[49] = '\0';
    strncpy(label, d.label, 19);
    label[19] = '\0';
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char * s, const char * s1, const char * s2, int n, double x) 
        : Cd(s1, s2, n, x) 
{
    strncpy(song, s, SONG_LEN - 1);
    song[SONG_LEN - 1] = '\0';
}

Classic::Classic(const char * s, const Cd & d) : Cd(d) {
    strncpy(song, s, SONG_LEN - 1);
    song[SONG_LEN - 1] = '\0';
}

Classic::Classic() : Cd() {
    song[0] = '\0';
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
    strncpy(song, c.song, SONG_LEN - 1);
    song[SONG_LEN - 1] = '\0';

    return *this;
}