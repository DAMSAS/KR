#include<stdio.h>
#include<string.h>
#define MAXLINE 1000
int getline1(char *line,int max);
main(int argc, char *argv[])
{
     char line[MAXLINE];
     int found = 0;
     if (argc!=2)
        printf("usage:find pattern\n");
     else
        while (getline1(line,MAXLINE)>0)
              if (strstr(line,argv[1])!=NULL) {
                 printf("%s",line);
                 found++;
              }
     return found;
}
int getline1(char *line,int max)
{
    char *t=line;
    int c;
    while (max-1>0 && (c=getchar())!=EOF && c!='\n')
          *line++=c;
    if (c=='\n')
       *line++=c;
    *line='\0'; 
    return line-t;
}
