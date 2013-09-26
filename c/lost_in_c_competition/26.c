#include<stdio.h>
#include<conio.h>

main()
{

int i,n;
scanf("%d",&n);
for(i=0;i<4;i++)
{
	int x=(n>>(3-i))<<3;
	x?printf("%d",0):printf("%d",1);
}

getch();
clrscr();
}

/*Input: 5*/
