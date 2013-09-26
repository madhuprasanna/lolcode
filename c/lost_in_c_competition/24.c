#include<stdio.h>
#include<conio.h>

#define STR(X) #X
main()
{

int a=3,b=5;
printf(&a["hai\nThis is %s\n"],&b["junk/super"]);
printf(&b["tryit %c %c %c %c"],a["---go"],b["fine one"],2["too"],0["do well"]);

getch();
clrscr();
}

