/*Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.*/

#include <stdio.h>
main()
{
     int c,p;
     while ((c = getchar()) != EOF){
           if (c==' ')
              if (p != ' ')
                 putchar(c);
           if (c!=' ')
              putchar(c);
           p = c;
     }
}
