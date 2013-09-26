#include<stdio.h>
#include<conio.h>

main()
{

func();
printf("%d",_AX);

getch();
clrscr();
}

func()
{
int i=4;
return i++;
}