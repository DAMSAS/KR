#include<stdio.h>
void strcat(char *,char *);
main()
{
     int i=0,c;
     char s[10],t[10];
     printf("enter string 1\n");
     for (i=0;i<9 && (c=getchar())!=EOF && c!='\n';i++)
         s[i]=c;
         s[i]='\0';
      printf("enter string 2\n");
      for (i=0;i<9 && (c=getchar())!=EOF && c!='\n';i++)
           t[i]=c;
           t[i]='\0';
      strcat(s,t);
      printf("modified string =%s\n",s);
      
}
void strcat(char*s,char*t)
{
       for (;*s!='\0';s++)
           ;
       while (*s++=*t++)
             ;
}
    
