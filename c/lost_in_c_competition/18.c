#include<stdio.h>
#include<conio.h>

char *c[]={"ENTRY","AND","COUNT","POINT"};
char **cp[]={c+3,c+2,c+1,c};
char ***cpp=cp;
main()
{

//printf("%s %s\n",c[0],*cp[0]);
printf("%s",cpp[1][3]);
++cpp;
//printf("%s",cpp[-1][-2]+3);

getch();
clrscr();
}

