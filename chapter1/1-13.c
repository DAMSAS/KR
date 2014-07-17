/*Write a program to print a histogram of the lengths of words in its input.*/

#include<stdio.h>
#define IN 1
#define OUT 0
#define maxlen 10
main ()
{ 
      int c = EOF;
      int l = 0;
      int j = 0;
      int wlen[maxlen+1];
      int state = IN;
      int nc = 0;
 
      for (l = 0; l <= maxlen; ++l)
          wlen[l] = 0;
  
     while ((c=getchar())!=EOF){
           ++nc;
          if (c==' '||c=='\n'||c=='\t'){
             state= OUT;
             --nc;
             }
          if (state==OUT){
             if (nc!=0 && nc<=maxlen){
                ++wlen[nc];
                state=IN;
                nc=0;
            }             
          } 
     } 
    for (l=1; l <= maxlen; ++l){
        printf("%2d:", l);
        for (j = 0; j < wlen[l]; ++j)
            putchar('*');
        putchar('\n');
      
    }
}
              
                 
     
     
       
