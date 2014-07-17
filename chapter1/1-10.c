/*Write a program to copy its input to its output, replacing each tab by \t , each
backspace by \b , and each backslash by \\ . This makes tabs and backspaces visible in an
unambiguous way.*/

#include <stdio.h>
main()
{
     int c;
     while ((c = getchar() )!=EOF){
          if (c == '\t')
              printf("TABB");
          else if ( c== '\\')
              printf("BACKSL");
          else if (c== '\b')
              printf("BACKSP");
          else
              putchar(c);
     }

}
