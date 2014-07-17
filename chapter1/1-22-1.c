#include<stdio.h>
/*Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n -th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.*/
#define lim 20
int getline1(void);
int getline2(void);
int i,j,c,k;
char s1[lim],s2[lim];
main()
{
	extern char s1[],s2[];
        getline1();
        getline2();
        printf("line1:%s\n",s1);
        printf("line2:%s\n",s2);
       
       
}
int getline1(void)
{
       extern int i,c;
       extern char s1[];
       for (i=0;i<lim-1&&(c=getchar())!=EOF && c!='\n';++i)
       	    s1[i]=c;
            s1[i]='\0';
         
}
 int getline2(void)
{
       extern int i,c;
       extern char s2[];
       for (i=0;i<lim-1&&(c=getchar())!=EOF && c!='\n';++i)
       	   s2[i]=c;
           s2[i]='\0';
         
}

     
