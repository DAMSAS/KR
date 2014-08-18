#include<stdio.h>
/*Adapt the ideas of printd to write a recursive version of itoa ; that is, convert
an integer into a string by calling a recursive routine.*/
void itoa(int n);
int i=0;
char s[100];
main()
{
     
      extern char s[100];
      int n;
      printf("enter a digit\n");
      scanf("%d",&n);
      itoa(n);
      printf("converted form =%s\n",s);
}
void itoa(int n)
{
      extern char s[100];
      extern int i;     
      if (n/10)
         itoa(n/10);
      s[i++]=(n%10+'0');
     
}
