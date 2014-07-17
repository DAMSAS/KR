/*Write a program to print the corresponding Celsius to Fahrenheit table.*/

#include <stdio.h>
main()
{ 
     int celsius;
     printf("celsius-Fahrenheit table\n");
     for (celsius=0;celsius<=300;celsius=celsius+20)
         printf("%3d %6.1f\n",celsius,(9.0/5.0)*celsius+32);

}


