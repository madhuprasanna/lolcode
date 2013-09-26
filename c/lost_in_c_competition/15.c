#include<stdio.h>
#include<conio.h>

main()
{

int i=-1,j=-1,k=0,l=1,m;
m=++i||++j&&++k||++l;
printf("%d %d %d %d %d",i,j,k,l,m);

getch();
clrscr();
}
