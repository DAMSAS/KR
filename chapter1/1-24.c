/*Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)*/

#include <stdio.h> 
#define MAXLINE 1000 
char line[MAXLINE]; 
int my_getline(void);  
int main() 
{
	int len = 0;
	int i = 0;
	int brace = 0, parenthesis = 0, brack = 0;
	int s_quote = 1, d_quote = 1;
	while ((len = my_getline()) > 0) {
	      i= 0;
	      while (i< len) {
		    if (line[i] == '{') {
		       brace++;
		    }
		    if (line[i] == '}') {
		       brace--;
		    }
		    if (line[i] == '[') {
		       brack++;
		    }
		    if (line[i] == ']') {
		       brack--;
		    }
		    if (line[i] == '(') {
		       parenthesis++;
		    }
		    if (line[i] == ')') {
		       parenthesis--;
		    }
		    if (line[i] == '\'') {
		       s_quote --;
		    }
		    if (line[i] == '"') {
		       d_quote --;
		    }
		    i++;
	     }
	}
	if (d_quote != 1)
	    printf("Mismatching double quote mark\n");
	if (s_quote != 1)
	    printf("Mismatching single quote mark\n");
	if (parenthesis != 0)
	   printf("Mismatching parenthesis\n");
	if (brace != 0)
	   printf("Mismatching braces\n");
	if (brack != 0)
	    printf("Mismatching bracket mark\n");
	if (brack == 0 && brace == 0 && parenthesis == 0 && s_quote == 1 && d_quote== 1)
	    printf("Syntax appears to be correct.\n");
	return 0;
}
	 
int my_getline(void) 
{
	int c, i;
	extern char line[];
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	    line[i] = c;
	if (c == '\n') {
	   line[i] = c;
	   ++i;
	}
	line[i] = '\0';
	return i;
	 
}


