#include<stdio.h>
int strend(char *,char *);
main()
{
     int i=0,c;
     char s[100],t[100];
     printf("enter string 1\n");
     for (i=0;i<99 && (c=getchar())!=EOF && c!='\n';i++)
         s[i]=c;
         s[i]='\0';
      printf("enter string 2\n");
      for (i=0;i<99 && (c=getchar())!=EOF && c!='\n';i++)
           t[i]=c;
           t[i]='\0';
      strend(s,t);
      printf("strend =%d\n",i=strend(s,t));
      
}
int strend(char*s,char*t)
{
       char *tp=t;
       char *ts=s;
       for (;*s!='\0';s++)
           ;
       for (;*t!='\0';t++)
           ;
       for (;*s==*t;s--,t--)
           if (s==ts || t==tp)
              break;
       if (*s==*t && t==tp)
          return 1;
       else
          return 0;
}
    
