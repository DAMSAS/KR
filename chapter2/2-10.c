#include<stdio.h>
/*Rewrite the function lower , which converts upper case letters to lower case,
with a conditional expression instead of if-else .*/
#define lim 40
int lower(int c);
main()
{
     int c,x,i,j;
     int s[lim];
     for (i = 0; i < lim; ++i)
		s[i] = '\0';
     printf("enter a string of characters\n");
     for(i=0;i<lim-1 && ((c=getchar())!='\n') ;++i){
        x=lower(c);
        s[i]=x;
        ++i;
     }
     j=i+1;

     printf("modified string\n");
     for(i=0;i<j;++i)
         printf("%c",s[i]);
     printf("\n");
}
int lower(int c)
{
     
      return(c>='A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
     
