#include<stdio.h>
/*Write a loop equivalent to the for loop above without using && or || .*/
#define lim 20
main()
{     int c,i,k;
      char s[lim];
      printf("Enter a line of texts\n");
      i=k=0;
      while (i<lim-1){
            
            if((c=getchar())!='\n'){
              
               if(c!=EOF){
                 s[i]=c;          
                 i++;
                 k++;              
               }
            }
            if(c=='\n')
              i=lim; 
      }
      printf("line entered\n");
      for(i=0;i<k;++i){
      printf("%c",s[i]);
      }
      printf("\n");            
}

