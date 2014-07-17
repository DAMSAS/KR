/*Rewrite the temperature conversion program of Section 1.2 to use a function
for conversion.*/
#include<stdio.h>
float c(float fahr);
main()
{
     float f; 
     printf("fahr to celcius\n");
     for (f=0;f<=300;f=f+20)
          printf("%3.0f %6.2f\n",f,c(f));
}

float c(float f)
{
    float a;
    a=  (5.0/9.0)*(f-32);
    return(a);
  
}

