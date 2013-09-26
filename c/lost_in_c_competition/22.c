#include<stdio.h>
#include<conio.h>

#define STR(X,Y) X##Y
main()
{

char x[10]="cse";
char y[10]="Rect";
printf("%s",STR(x,y));

getch();
clrscr();
}

