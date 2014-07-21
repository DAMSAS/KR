#include<stdio.h>
/*Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.*/
unsigned rightrot(unsigned x, int n);
main()
{
     unsigned x,y;
     int n;
     printf("enter a value\n");
     scanf("%u",&x);
     printf("enter no of positions required to rotate right\n");
     scanf("%d",&n);
     y=rightrot(x,n);
     printf("no after rotated to %d position to right=%u\n",n,y);
}

unsigned rightrot(unsigned x, int n)
{
     while(n > 0){
          if(x & 1 == 1)
            x=(x>>1)|(~(~0>>1));
          else
            x=(x>>1);
          n--;
     }
     return x;
}
 
