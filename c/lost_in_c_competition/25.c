#include<stdio.h>
#include<conio.h>

#define INTPTR int*
main()
{

INTPTR x,y;
int a1=1,a2=2;
y=&a1;x=&a2;
printf("%d %d %d %d",*x,*y);

getch();
clrscr();
}

