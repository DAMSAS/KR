#include<stdio.h>
/*Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s . Use a switch . Write
a function for the other direction as well, converting escape sequences into the real characters.*/
#define lim 50
int getline1(void);
void escape(void);
char s[lim];
char t[lim];
int i,c,j;
main()
{
     
     extern char s[lim],t[lim];
     printf("enter a line of characters\n");
     getline1();
     printf("line entered =%s\n",s);
     escape();
     printf("modified line =%s\n",t);
    
}
int getline1(void)
{
    extern char s[lim];
    extern int c,i;
    for (i=0;i<lim-1 && (c=getchar())!= EOF;++i)
        s[i]=c;
        s[i]='\0';
}
void escape(void)
{
    extern char s[lim],t[lim];
    extern int i,j;
    for (i=0;s[i]!='\0';++i){
        switch (s[i]){
        case '\t':
             t[j++]='/';
             t[j++]='t';
             break;
        case '\n':
             t[j++]='/';
             t[j++]='n';
             break;
        default:
             t[j++]=s[i];
             break;
        } 
    }
    s[j]='\0';
}          
       
