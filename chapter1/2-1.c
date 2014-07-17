#include <limits.h>
/*Write a program to determine the ranges of char , short , int , and long
variables, both signed and unsigned , by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.*/
#include<stdio.h>
main()

{
     printf("maximum value of sighned char: %d \n",SCHAR_MAX);
     printf("minimum value of sighned char:%d\n",SCHAR_MIN);
     printf("maximum value of int:%d\n",INT_MAX);
     printf("minimum value of int:%d\n",INT_MIN);
     printf("maximumm value of long:%lu\n",LONG_MAX);
     printf("minimum value of long:%lu\n",LONG_MIN);
     printf("maximumm value of short:%d\n",SHRT_MAX);
     printf("minimum value of short:%d\n",SHRT_MIN);
     printf("maximumm value of unsighned char:%d\n",UCHAR_MAX);
     printf("maximumm value of unsighned int :%d\n",UINT_MAX);
     printf("maximumm value of unsighned long:%lu\n",ULONG_MAX);
     printf("maximumm value of unsighned short:%d\n",USHRT_MAX);
}
 
 
