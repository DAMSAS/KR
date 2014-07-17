/*Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter*/

#include <stdio.h>
#define MAXLINE 1000
char line[MAXLINE];
int my_getline(void);
main()
{       int len;        
        while ((len=my_getline())>0){
              printf("%s",line);
        }
        return 0; 
}

int my_getline(void)
 {
	int c, i,j;
        int tabsize;
        tabsize=5;
	extern char line[];
	for (i = 0; i < MAXLINE - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
            if(c=='\t'){
              for(j=0;j<tabsize;++j){
                 line[i]=' ';
                 ++i;
              }
            }
       
            else 
                line[i] = c;
	    if (c == '\n') {
	       line[i] = c;
	       ++i;
            }
	    line[i] = '\0';
	    return i;
}

