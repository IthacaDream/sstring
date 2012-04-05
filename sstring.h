#ifndef SSTRING_H_
#define SSTRING_H_

#include <iostream>
#include <string.h>
#include <assert.h>

class sstring
{

public:
    sstring();
    sstring(const char*);
    sstring(const sstring&);
    virtual ~sstring();
    
    sstring & operator=(const sstring&);
    sstring & operator+=(const sstring&);

    char& operator[](const unsigned int i);
    const char& operator[](const unsigned int i) const;

    const char *c_str() const;

    unsigned int length() const;
    unsigned int size() const;
    bool empty()const;


    friend sstring operator+(const sstring&, const sstring&);  
    friend bool operator==(const sstring&, const sstring&);  
    friend bool operator!=(const sstring&, const sstring&);  
    friend bool operator>(const sstring&, const sstring&);  
    friend bool operator>=(const sstring&, const sstring&);  
    friend bool operator<(const sstring&, const sstring&);  
    friend bool operator<=(const sstring&, const sstring&);  

    friend std::ostream & operator<<(std::ostream&, const sstring&);
    friend std::istream & operator>>(std::istream&, sstring&);
    
    //sstring substring(unsigned int);
    //sstring substring(unsigned int, unsigned int);

private:
    char *m_str;
    unsigned int m_size;
};


#endif
