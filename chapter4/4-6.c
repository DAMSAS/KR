#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
/*Add commands for handling variables. (It's easy to provide twenty-six variables
with single-letter names.) Add a variable for the most recently printed value.*/
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
main ()
{
     int i,type,var=0;
     double op2,op1,v;
     char s[MAXOP];
     double variable[26];
     for (i=0;i<26;i++)
         variable[i]=0.0;
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
           case '=':
                pop();
                if (var >='A'&& var <='Z')
                   variable[var-'A']=pop();
                else
                   printf("error:no variable name\n");
                break;
           case '\n':
                v=pop();
                printf("\t%.8g\n", v);
                break;
           default:
                if (type>='A' && type<='Z')
                   push(variable[type-'A']);
                else if (type =='v')
                      push(v);
                else
                   printf("error:unknown command\n");
                break;
           }
            
           var = type;           
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
