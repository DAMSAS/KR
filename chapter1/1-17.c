/*Write a program to print all input lines that are longer than 80 characters.*/

#include <stdio.h>
#define MAXLINE 1000
#define MAX 11	
char line[MAXLINE];
int my_getline(void);
main()
{       int len;
        len=my_getline();
        if (len>MAX)
           printf("line entered:%s",line);
        
}

int my_getline(void)
{
	int c, i;
	extern char line[];
	for (i = 0; i < MAXLINE - 1&& (c=getchar()) != EOF && c != '\n'; ++i)
	    line[i] = c;
	if (c == '\n') {
	   line[i] = c;
	   ++i; 
        }
	line[i] = '\0';
	return i;
}

