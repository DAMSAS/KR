#include<stdio.h>
/*Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s , or -1 if there is none.*/
#define MAXLINE 1000
int my_getline(char line[],int max);
int strindex(char source[],char searchfor[]);
char pattern[]="uld";
main()
{
     char line[MAXLINE];
     int k;
     while (my_getline(line,MAXLINE)>0){
           if (strindex(line,pattern)>=0) {
              k=strindex(line,pattern);
              printf("position of right most occurrence of uld=%d\n",k);
              printf("%s",line);
             
           }
      
           else if (strindex(line,pattern)<0){
                    k=strindex(line,pattern);
                    printf("value=%d\n",k);
           }
    }
   

}

int my_getline(char s[],int lim)
{
    int c,i;
    i=0;
    while (--lim>0 && (c=getchar())!= EOF && c!='\n')
          s[i++]=c;
    if (c=='\n')
       s[i++]=c;
     s[i]='\0';

    return i;
}
int strindex(char s[],char t[])
{
    int i,j,k,r;
    r=-1;
    for (i=0;s[i]!='\0';++i){
        for (j=i,k=0;t[k]!='\0'&& s[j]==t[k];k++,j++)
            ;
        if (k>0 && t[k]=='\0')
            r=i;
    }
    return r;
    

}


