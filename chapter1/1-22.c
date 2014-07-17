/*Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n -th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.*/

#include "stdio.h" 
#define MAXSIZE 1000 
#define FOLD 50
char line[MAXSIZE]; 
int get_line(void);  
main()
{
     int i,len;
     int devider, space;
     while ((len = get_line()) > 0 ){
           if ( len > FOLD ){
              i = 0;
              devider= 0;
              while (i<len){
                    if(line[i] == ' ')
                       space = i;
                    if(devider==FOLD) {
                      line[space] = '\n';
                      devider = 0;
                      
                     }
                     devider++;
                     i++;
             }
           }
           
    }
    printf ( "%s", line);
}
int get_line(void)
{
     int c, i;
     extern char line[];
     for ( i=0;i<MAXSIZE-1 && ( c=getchar()) != EOF && c != '\n'; ++i)
         line[i] = c;
     if(c == '\n'){
       line[i] = c;
       ++i;
     }
     line[i] = '\0';
     return i;
 
}
