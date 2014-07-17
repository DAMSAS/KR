/*Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.*/

#include <stdio.h>
#define MAXLINE 1000
int max;
char line[MAXLINE];
char longest[MAXLINE];
int getline1(void);
void copy(void);
main()
{       int len;
        extern int max;
        extern char longest[];
        max = 0;
        while((len=getline1())>0){
             printf("%d: %s",len,line);
             if (len>max){
                max = len;
                copy();
             }
        }
        if (max>0)
        printf("Longest Line is %d characters:%s", max, longest);
        return 0; 
}

int getline1(void)
{
	int c, i;
	extern char line[];
	for (i = 0; i < MAXLINE - 1 && (c=getchar())!=EOF && c!='\n'; ++i)    
	    line[i] = c;
	if (c == '\n') {
	    line[i] = c;
	    ++i; }
	line[i] = '\0';
	return i;
}
void copy(void)
{
       int i;
       extern char line[], longest[];
       i = 0;
       while ((longest[i] = line[i]) != '\0')
             ++i;
}


        
        
