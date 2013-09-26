#include<stdio.h>
#include<conio.h>

main()
{

int x=4,y=6;
y=++x * ++x * ++x;
printf("%d %d",x,y);
/*First `x++' increments x to 5 and second to 6 and third to 7.As all of
these x's expressions are with in a sequence point,the change will be
reflected in all x's(i.e. 7*7*7 instead of 5*6*7)
*/

getch();
clrscr();
}

