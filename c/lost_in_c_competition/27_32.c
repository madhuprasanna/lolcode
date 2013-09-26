/************************************************************************
27.What is the difference between sizeof() and strlen()?

28.What is the difference between malloc and calloc?

29.What is the difference between memcopy and memmove?

30.What is the difference between `const char *ptr' and `char const *ptr'?

31.Write a program to find if a system is BIG ENDIAN or LITTLE ENDIAN?

32.Write a program to find whether the system stack grows upwards
   or downwards?
*************************************************************************/


#include<stdio.h>
#include<conio.h>

main()
{

char *first,*second;

first=(char*)malloc(1);
second=(char*)malloc(1);

printf("first: %d \nsecond: %d \ndiff: %d",first,second,first-second);


getch();
clrscr();
}

