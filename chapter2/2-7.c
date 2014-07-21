#include<stdio.h>
/*Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/
unsigned invert(unsigned x,int p,int n);
main()
{
     unsigned x,b;
     int p,n;
     printf("enter a value\n");
     scanf("%u",&x);
     printf("enter position\n");
     scanf("%d",&p);
     printf("enter no of bits\n");
     scanf("%d",&n);
     b = invert(x,p,n);
     printf("inverted form:%u\n",b);
}

unsigned invert(unsigned x,int p,int n)
{
     return x^(~(~0<<n)<<(p+1-n));
}
     


