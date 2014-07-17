/*Write a program to print a histogram of the frequencies of different characters
in its input.*/


#include <stdio.h>
main()
{
     int i,c,j;
     int chars[255];
     for (i=0;i<=255;++i)
         chars[i]=0;
     while ((c=getchar())!=EOF) 
           ++chars[c];
     for (i=0;i<=255;++i){
         if (chars[i]!=0) {
            if (i ==' ')
               printf("space: ");
            else if (i=='\t')
                    printf("  tab: ");
            else if (i=='\n')
                    printf("   \\n: ");
            else 
                printf("%5c: ",i);
            for (j=0;j<chars[i];++j)
                putchar('*');
            putchar('\n');

           } 
         }
}
 
                   
 
    
