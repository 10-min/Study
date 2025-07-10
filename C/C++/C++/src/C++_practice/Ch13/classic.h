#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd {
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd {
private:
    enum {SONG_LEN = 40};

    char song[SONG_LEN];
public:
    Classic(const char * s, const char * s1, const char * s2, int n, double x);
    Classic(const char * s, const Cd & d);
    Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & c);
};

#endif