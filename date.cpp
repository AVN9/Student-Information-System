#include<iostream>
#include<time.h>
#include<string>
using namespace std;
int main()
{
time_t ta;
string s1;
ta=time(NULL);
s1 = ctime(&ta);
for(int i=20;i<25;i++)
cout<<s1[i];
return (0);
}
