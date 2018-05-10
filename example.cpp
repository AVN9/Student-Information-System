#include<iostream>
#include<fstream>
using namespace std;
class a
 {
int x;
char y;
  public:
 void insert(void)
 {
  x=10;
  y='a';
 }
  void dis(void)
  {
   cout<<x<<'\n'<<y;
  }
};
int main()
{ 
a s;                  
fstream file,file1;
//s.insert();
             
file.open("rec.dat",ios::ate|ios::app|ios::in|ios::out);
// file.write((char *) & s,sizeof(s));
  file.close();
//s.dis();
//file.open("rec.dat", ios::in|ios::out);

 file1.open("rec1.dat",ios::out);
          while(file.read((char *) & s,sizeof(s)))
          {
           s.dis();
             file1.write((char *) & s,sizeof(s)); 
                }
                                 file.close();
                                 file1.close();
  return (0);
}
