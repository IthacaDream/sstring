#include "sstring.h"
#include <iostream>

using namespace std;


int main()
{
    sstring s1;
    sstring s2("hello");
    sstring s3("world");
    s1=s2+" "+s3;
    cout<<s2<<endl
	<<s3<<endl
	<<s1<<endl;
    cin>>s1;
    cout<<s1<<endl;

}
