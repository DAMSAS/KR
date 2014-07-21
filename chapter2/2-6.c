#include<stdio.h>
/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
position p set to the rightmost n bits of y , leaving the other bits unchanged.*/
unsigned setbits(unsigned x, int p,int n,unsigned y);
main()
{
     unsigned x,y,z;
     int p,n;
     printf("enter first number\n");
     scanf("%u",&x);
     printf("enter second number\n");
     scanf("%u",&y);
     printf("enter position\n");
     scanf("%d",&p);
     printf("enter number of bits\n");
     scanf("%d",&n);
     z=setbits(x,p,n,y);
     printf("modified number=%u\n",z);
}
unsigned setbits(unsigned x, int p,int n,unsigned y)
{
     
     unsigned y1,y2,x1,x2;
     y1 = y&(~(~0<<n));
     y2 = y1<<(p+1-n);
     x1 = ~((~(~0<<n))<<(p+1-n));
     x2 = (x1&x);
     return (x2|y2);
}
