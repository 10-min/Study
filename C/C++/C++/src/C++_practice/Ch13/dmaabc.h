#ifndef DMAABC_H_
#define DMAABC_H_
#include <iostream>

class baseDMA {
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l = "null" , int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    virtual void View() const = 0;
};

class lacksDMA : public baseDMA {
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    virtual void View() const;
};

class hasDMA : public baseDMA {
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
            int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    virtual void View() const;
};

#endif