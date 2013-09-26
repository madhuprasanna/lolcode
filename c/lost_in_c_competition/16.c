#include<stdio.h>
#include<conio.h>

int i;
main()
{
printf("%d",f()+g());

getch();
clrscr();
}

f()
{
return i++;
}

g()
{
return i;
}