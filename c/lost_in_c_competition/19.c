#include<stdio.h>
#include<conio.h>

static char *s[]={"YOU","PEOPLE","MUST","PRACTICE"};
static char **ptr[]={s+3,s+2,s+1,s};
char ***p=ptr;
main()
{

printf("\n%s",**++p);
printf("\n%s",**++p+3);
printf("\n%s",*p[-2]+3);

getch();
clrscr();
}

