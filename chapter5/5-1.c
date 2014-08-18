#include<stdio.h>
#include<ctype.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
int getch(void);
void ungetch(int);
int getint(int *);
main()
{
    int r ;
    getint(&r);
    printf("%d\n", r);    

}
int getint(int *pn)
{
    int c,sign,p;
    while (isspace(c=getch()))
          ;
    if (!isdigit(c) && c!=EOF && c!='+' && c!='-') {
       ungetch(c);
       return 0;
    }
    sign=(c=='-')?-1:1;
    if (c=='+'|| c=='-') {
       p=c;
    if (!isdigit(c=getch()))
       if (c!=EOF) {
          ungetch(c);
       ungetch(p);
       return(p);
       }
    }
    c=getch();
    for (*pn=0;isdigit(c);c=getch())
         *pn=10**pn+(c-'0');
         *pn*=sign;
    if (c!=EOF)
       ungetch(c);
       return c;
}
int getch(void)
{
     return (bufp>0)?buf[--bufp]:getchar();
}
void ungetch(int c)
{
     if (bufp>=BUFSIZE)
        printf ("ungetch:too many characters\n");
     else 
        buf[bufp++]=c;
}   
