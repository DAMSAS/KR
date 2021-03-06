#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
/*Add the commands to print the top elements of the stack without popping, to
duplicate it, and to swap the top two elements. Add a command to clear the stack.*/
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define MAXOP 100

int sp=0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp=0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void clear(void);
main ()
{
     int type;
     double op2,op1;
     char s[MAXOP];
     printf("choose any one of the following keys\n");
     printf("C : to clear the stack, S:to swap to elements, D : to duplicate an element, ENTER : to print the top element\n");
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
           case '\n':
                printf("\t%.8g\n", pop());
                break;
           case 'D':
                op1=pop();
                push(op1);
                push(op1);
                break;
           case 'S':
                op1=pop();
                op2=pop();
                push(op1);
                push(op2);
                break;
           case 'C':
                 clear();
                 break;
           case '?': 
		 op1 = pop();
		 printf("top element : %.8g\n", op1);
                 push(op1);
		 break;
          
           
         
          }
     }
     return 0;
}
void clear(void)
{
	sp = 0;
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
