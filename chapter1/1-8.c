/*Write a program to count blanks, tabs, and newlines.*/

#include <stdio.h>
main()
{
      int b,t,nl,nc,c;
      b =t=nl=nc=0;
      while ((c = getchar() )!=EOF){
            ++nc;
            if (c == '\n')
               ++nl;

            if (c == '\t')
               ++t;

            if (c == ' ')
               ++b;
      }

      printf("Blanks: %d\nTabs: %d\nLines: %d\nChar:%d\n",b,t,nl,nc);


}
