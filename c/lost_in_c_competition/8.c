#include<stdio.h>
#include<conio.h>

main()
{

char a,b;
int i;
i=scanf("%c%*%c",&a,&b);
/*`*'-Omits the remaining of the input atfer it occurs.So,only `a' gets stored
   and scanf returns the number of characters it has successfully scanned,
   converted and stored(only `a' in this case).
*/
printf("%d %c %c",i,a,b);

getch();
clrscr();
}

/*Input: abc*/