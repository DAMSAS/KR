#include<stdio.h>
#include<string.h>
#define lim 50
/*In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2 wordsize-1 ). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.*/
void itoa(char s[lim],int n);
void reverse(char s[lim]);
main()
{
     int n;
     char s[lim];
     printf("enter an integer\n");
     scanf("%d",&n);
     itoa(s,n);
     printf("integer converted to a string =%s\n",s);
}
void itoa(char s[lim],int n)
{
     int sign,i;
     if ((sign=n)<0)
        n=-n;
     i=0;
     do {
        s[i++]=n%10+'0';
     } while ((n/=10)>0);
     if (sign<0)
        s[i++]='-';
     s[i]='\0';
     reverse(s);
}
void reverse(char s[lim])
{    
   int i,j,c;
   for (i=0,j=strlen(s)-1;i<j;i++,j--)
       c=s[i],s[i]=s[j],s[j]=c;
}
