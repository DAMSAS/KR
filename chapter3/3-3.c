#include<stdio.h>
/*Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2*/
#define lim 4
void expand(char s1[lim],char s2[30]);
main()
{
     int i,c;
     char s1[lim],s2[30];
     printf("enter your shorthand notations like a-z or 0-9\n");
     for(i=0;i<lim-1 && (c=getchar())!='\n' && c!=EOF;++i)
        s1[i]=c;
        s1[i]='\0';
     expand(s1,s2);
     printf("expanded form =%s\n",s2);
}
void expand(char s1[lim],char s2[])
{
     int i,j;
     char c;
     i=j=0;
     if(s1[i]!='\0'){
       c=s1[i];
       if(s1[i+1]=='-' && s1[i+2]>s1[i]){
         while(c<=s1[i+2]){
              s2[j++]=c;
              c++;
         }     
       }
       else
         s2[j++]=c;
      }
      s2[j]='\0';
}

