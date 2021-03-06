/*Add access to library functions like sin , exp , and pow . See <math.h> in*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define MAXVAL 100
#define BUFSIZE 100

int sp=0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp=0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void mathfnc(char s[]);
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
           case '-':
                op2=pop();
                push(pop()-op2);
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
          case NAME:
               mathfnc(s);
	       break;

          case '\n':
                printf("\t%.8g\n", pop());
                break;
         
          }
     }
     return 0;
}
void mathfnc(char s[])
{
	double op2;

	if (strcmp(s,"sin") == 0)
		push(sin(pop()));
	else if (strcmp(s,"cos") == 0)
		push(cos(pop()));
	else if (strcmp(s,"exp") == 0)
		push(exp(pop()));
	else if (strcmp(s,"pow") == 0) {
		op2 = pop();
		push(pow(pop(),op2));
	} else 
		printf("Invalid code:\n");
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
    int i,c;
    while((s[0]=c=getch())==' ' || c=='\t')
         ;
    s[1]='\0';
    i=0;  
    if (islower(c)){
	while (islower(s[++i] = c = getch()))
	      ;
        s[i] = '\0';
        if (c != EOF)
            ungetch(c);
        if (strlen(s) > 1)
            return NAME;
        else 
            return c;
    }
    if (!isdigit(c) && c!='.' && c!='-')
       return c;
    
    if (isdigit(c))
       while (isdigit(s[++i] = c = getch()))
              ;
       if (c == '.')
	   while (isdigit(s[++i] = c = getchar()))
                 ;         
    s[i]='\0';
    if (c!=EOF)
       ungetch(c);
    return NUMBER;
}
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
       printf("ungetch: too many characters\n");
    else 
	buf[bufp++] = c;
}
