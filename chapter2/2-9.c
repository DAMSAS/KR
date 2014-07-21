#include<stdio.h>
/*In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x . Explain why. Use this observation to write a faster version of bitcount .*/
int bitcount(unsigned x);
main()
{     
      unsigned x;
      int b;
      printf("enter a value\n");
      scanf("%u",&x);
      b = bitcount(x);
      printf("no of 1 bits:%d\n",b);
}

int bitcount(unsigned x)
{        
       
       int b;
       for (b=0;x!=0;x&=x-1)
            b++;
       return b;
      
}         
      



