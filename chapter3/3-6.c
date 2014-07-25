#include<stdio.h>
/*Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks on the
left if necessary to make it wide enough.*/
#include<string.h>
#define lim 50
void itoa(void);
void reverse(void);
char s[lim];
int n,p,i,j,sign,c;
main()
{
     extern int n,p;
     extern char s[lim];
     printf("enter an integer\n");
     scanf("%d",&n);
     printf("enter a field width\n");
     scanf("%d",&p);
     itoa();
     printf("integer converted to a string =%s\n",s);
}
void itoa(void)
{
     extern int sign,i,n,p;
     extern char s[lim];
     if ((sign=n)<0)
        n=-n;
     i=0;
     do {
        s[i++]=n%10+'0';
     } while ((n/=10)>0);
     if (sign<0)
        s[i++]='-';
     while (i<p)
          s[i++]=' ';
     s[i]='\0';
     reverse();
}
void reverse(void)
{    
   extern char s[lim];
   extern int i,j,c;
   for (i=0,j=strlen(s)-1;i<j;i++,j--)
       c=s[i],s[i]=s[j],s[j]=c;
}
