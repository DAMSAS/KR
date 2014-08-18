#include<stdio.h>
#define lim 100
int getline1(char *);
main()
{
    char s[lim];
    int i;
    printf("enter a string of characters\n");
    i = getline1(s);
    printf("length of the string =%d\n",i);
}
int getline1(char *s)
{
    char *t=s;
    int c;
    while (lim-1>0 && (c=getchar())!=EOF &&c!='\n')
          *s++=c;
    if (c=='\n')
       *s++=c;
    *s='\0';
    return s-t;
}
   
    
