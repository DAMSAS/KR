/*An alternate organization uses getline to read an entire input line; this makes
getch and ungetch unnecessary. Revise the calculator to use this approach.*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 100
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXLINE 100
int sp=0;
double val[MAXVAL];
int li=0;
int line[MAXLINE];

int getop(char []);
void push(double);
double pop(void);
int get_line(int [], int);

main ()
{
     int type;
     double op2;
     char s[MAXOP];
     while ((type=getop(s))!=EOF){
           switch (type) {
           case NUMBER:
                push(atof(s));
                break;
           case '+':
                push(pop()+pop());
                break;
           case '*':
                push(pop()*pop());
                break;
           case '/':
                op2=pop();
                if (op2!=0.0)
                   push(pop()/op2);
                else
                   printf("error : zero divisor\n");
                break;
           case '%':
                 op2=pop();
                 if (op2!=0.0)
                    push((int)pop()%(int)op2);
                 else
                    printf("error\n");
                 break;
          case '\n':
                printf("\t%.8g\n", pop());
                break;
         
          }
     }
     return 0;
}

void push(double f)
{
    
     if (sp<MAXVAL)
        val[sp++]=f;
     else
        printf("Error: stack full, cann't push %g", f);
}
double pop(void)
{
    if (sp>0)
       return val[--sp];
    else {
         printf("error : stack empty");
	 return 0.0;
    }
}
int getop(char s[])
{
	int i, c;
        if (line[li] == '\0')
	   if (get_line(line,MAXLINE) == 0)
	       return EOF;
	   else
	       li = 0;
	while ( (s[0] = c = line[li++]) == ' ' || c == '\t')
	      ;
        s[1] = '\0';
	if (!isdigit(c) && c != '.')    
	   return c; 
        i = 0;
        if (isdigit(c))
	   while (isdigit(s[++i] = c = line[li++]))
		  ;
        if (c == '.')
	    while (isdigit(s[++i] = c = line[li++]));
			;
        s[i] = '\0';
	if (line[li] == '\0') 
	   li--;
	return NUMBER;
}
int get_line(int line[], int MAX)
{
	int c, i = 0, j = 0;
        while ( --MAX > 0 &&( (c = getchar()) != EOF) )
	      line[i++] = c;
        if (c == '\n')
	   line[i] = c;
        line[i] = '\0';
	return i;
}

