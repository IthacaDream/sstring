#include "sstring.h"

sstring::sstring()
{
    m_str = new char[1];
    m_str[0] = '\0';
    m_size = 0;
}

sstring::sstring(const char* s)
{
    if(s == NULL){
	m_str = new char[1];
        m_str[0] = '\0';
	m_size=0;
    }
    else{  
	m_size=strlen(s);
        m_str = new char[m_size+1];
        strcpy(m_str,s);
    }
}

sstring::sstring(const sstring& s)
{
    m_str = new char[strlen(s.c_str())+1];
    strcpy(this->m_str,s.c_str());
    this->m_size = s.length();

}

sstring::~sstring()
{
    delete[] m_str;
    m_str=NULL;
}

sstring& sstring::operator=(const sstring& s)
{
    if(*this == s)
	return *this;
    delete[] m_str;
    m_str=new char[strlen(s.c_str())+1];
    strcpy(m_str,s.c_str());
    m_size=s.length();
    return *this;
}

sstring& sstring::operator+=(const sstring& s)
{
    m_size = strlen(m_str)+strlen(s.c_str());
    char *tmp = new char[m_size + 1];
    strcpy(tmp, m_str);
    strcpy(tmp + strlen(m_str), s.c_str());
    delete[] m_str;
    m_str= tmp;
    return *this;
}

char& sstring::operator[](const unsigned int i)
{
    assert(i<m_size);
    return m_str[i];
}
const char& sstring::operator[](const unsigned int i) const
{
    assert(i<m_size);
    return m_str[i];
}


unsigned int sstring::length() const
{
    return m_size;
}

unsigned int sstring::size() const
{
    return m_size;
}

bool sstring::empty() const
{
    return m_size==0 ? true:false ;
}

const char* sstring::c_str() const
{
    return m_str;
}
/*
sstring sstring::substring(unsigned int start)
{
    assert(start < m_size);
    return sstring(m_size + start);
}

sstring sstring::substring(unsigned int start, unsigned int len)
{
    assert(start < m_size); 

    if(start+len < m_size){
	char* tmp = new char[len+1];
	strncpy(tmp,m_str+start, len);
	tmp[len]='\0';
	sstring s(tmp);
	delete[] tmp;
	return s;
    }
    else
	return sstring(m_size + start); 
}
*/
///////////////////////////////////////////////////////////////

sstring operator+(const sstring& lhs, const sstring & rhs)
{
    sstring str(lhs);  
    str += rhs;
    return str;
}

sstring operator+(const sstring& lhs,const char* rhs)
{

    return lhs + sstring(rhs);
}

bool operator<(const sstring& lhs, const sstring& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str())<0 ? true : false;
}

bool operator<=(const sstring&  lhs, const sstring& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str())<=0 ? true : false;
}

bool operator==(const sstring& lhs, const sstring& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str())==0 ? true : false;
}

bool operator!=(const sstring& lhs, const sstring& rhs)
{
    return !(lhs==rhs);
}


bool operator>(const sstring& lhs, const sstring& rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const sstring& lhs, const sstring& rhs)
{
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& out, const sstring& s)
{
    out << s.c_str();
    return out;
}

std::istream& operator>>(std::istream& in, sstring& s)
{
    char tmp[100000]={'\0'}; //TODO
    in >> tmp;
    s=sstring(tmp);
    return in;
}
