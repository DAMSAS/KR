/*Write a function reverse(s) that reverses the character string s . Use it to
write a program that reverses its input a line at a time.*/

#include <stdio.h>
#include<string.h>
#define MAXLINE 40
char line[MAXLINE];
char s[MAXLINE];
int my_getline(void);
void reverse(void);
main()
{       int len,p;
        while((len=my_getline())>0){
             reverse();
             printf("reversed line:%s",s);
        }
}
int my_getline(void)
{
	int c, i;
	extern char line[];
	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
	    line[i] = c;
            line[i] = '\0';
	return i;
}
void reverse(void)
{
        int k,i;
        extern char line[], s[];
        i=0;
        k= strlen(line)-1;
        while ((s[i] = line[k])) {
             ++i;
             --k;
       }
}

