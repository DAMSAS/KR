/*How would you test the word count program? What kinds of input are most
likely to uncover bugs if there are any?

answer,
## lines with zero words
## lines with tabs and space
## words after some blanks
## no words just new lines                                             */


#include <stdio.h>
#define IN 1
#define OUT 0
main()
{
      int c,nl,nw,nc,state;
      state = OUT;
      nl = nw = nc = 0;
      while ((c = getchar()) != EOF) {
            ++nc;
            if (c == '\n')
                ++nl;
            if (c ==' '|| c =='\n'|| c =='\t')
                state = OUT;
            else if (state == OUT) {
                     state = IN;
                     ++nw;
             }
      }
      printf("LINES:%d WORDS:%d CHARACTERS:%d\n",nl,nw,nc);
}

