/*Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.*/

#include <stdio.h>
#define MAXLINE 1000
char line[MAXLINE];
int my_getline(void);
main()
{       int len;
        while((len=my_getline())>0){
             printf("%s",line);}
        return 0; 
}

int my_getline(void)
{
	int c, i;
	extern char line[];
	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'&&c!=' '&&c!='\t'; ++i)
	    line[i] = c;
	
	line[i] = '\0';
	return i;
}
