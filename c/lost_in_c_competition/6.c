#include<stdio.h>
#include<conio.h>

union x
{
	int a;
	float b;
};

main()
{

union x a ={1,1.5};
printf("%d",a.a);

getch();
clrscr();
}
