#include<stdio.h>
#include<conio.h>

char input[]="SSGOOEDM1\1\11X\10ELRN\1\1G";
main()
{

int i,c,j=0;
for(i=1;(c=input[i])!='\0';i++)
{
	switch(c)
	{
		case 'a': putchar('i');continue;
		case '1': break;
		case 1: while((c=input[++i])!='\1'&&c!='\0');
		case 9: putchar('V');
		case 'E':
		case 'L':continue;
		default: putchar(c);continue;
	}
putchar(' ');
}
putchar('\n');


getch();
clrscr();
}

