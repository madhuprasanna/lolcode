#include<stdio.h>
#include<conio.h>

main()
{

int i=1,j;
j=sizeof(i++);
printf("%d %d",i,j);

getch();
clrscr();
}
