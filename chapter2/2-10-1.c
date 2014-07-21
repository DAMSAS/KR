#include<stdio.h>
/*Rewrite the function lower , which converts upper case letters to lower case,
with a conditional expression instead of if-else .*/
int lower(void);
main()
{    
     printf("enter a character\n");
     putchar(lower());
     putchar('\n');
         
}     
int lower(void)
{   
    int c;
    while(c=getchar()){
         return(c >='A' && c <='Z')?(c+'a'-'A'):c;
    }    
}

