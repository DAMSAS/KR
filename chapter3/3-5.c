#include<stdio.h>
/*Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s . In particular, itob(n,s,16) formats s as a
hexadecimal integer in s .*/
#include<string.h>
void itob(int n,char s[],int b);
void reverse(char s[]);
main()
{
     
     char s[50];
     int n,b; 
     printf("enter an integer value\n");
     scanf("%d",&n);
     printf("enter the base required\n");
     scanf("%d",&b);
     itob(n,s,b);
     printf("%d in base %d form :%s\n",n,b,s);
}
void itob(int n,char s[],int b)
{
    int i,j,sign;
    if ((sign=n)<0)
       n=-n;
    i=0;
    do{
        j=n%b;
        s[i++]=(j<=9)?j+'0':j+'a'-10;
       } while((n/=b)>0);
    if(sign<0)
      s[i++]='-';
      s[i]='\0';
    reverse(s);
}
void reverse(char s[])
{    
   int i,j,c;
   for (i=0,j=strlen(s)-1;i<j;i++,j--)
       c=s[i],s[i]=s[j],s[j]=c;
}
        
    
