#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAXOP 100
#define NUMBER '0'
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
void ungets(char []);
main (int argc, char *argv[])
{
     double op2;
     char s[MAXOP];
     while (--argc > 0) {
           ungets(" ");
           ungets(*++argv);
           switch (getop(s)) {
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
            default :
                 printf("error:unknown command %s\n",s);
                 argc=1;
                 break;             
          }
      }
      printf("\t%.8g\n", pop());
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
    int i,c;
    while((s[0]=c=getch())==' ' || c=='\t')
          ;     
    s[1]='\0';
    
    i=0;
    if (!isdigit(c) && c!='.' && c!='-')
       return c;
    if (c=='-')
       if (isdigit(c=getch()) || c=='.')
          s[++i]=c;
    else {
         if (c!=EOF)
            ungetch(c);
          return '-';
    }
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
void ungets(char s[])
{
    int len = strlen(s);
    void ungetch(int);
    while (len > 0)
          ungetch(s[--len]);
}
    
