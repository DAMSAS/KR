/*Modify the temperature conversion program to print a heading above the table.*/

#include <stdio.h>
main()
{ 
     int fahr;
     printf("Fahrenheit-Celsius table\n");
     for (fahr=0;fahr<=300;fahr=fahr+20)
         printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
}


