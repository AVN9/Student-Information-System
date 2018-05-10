#include<iostream>
#include<ncurses>
using namespace std;
int main()
{
int r,c;
for(r=30;r<50;r++)
{
gotoxy(r,30);
printf("*");
}
}
