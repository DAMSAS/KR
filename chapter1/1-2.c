#include <stdio.h>
/*print fahrenheit-celsius table for fhar=0,20,..........,300*/
main()
{

     int fahr,celsius,lower,upper,step;
     lower=0;
     upper=300;
     step=20;
     fahr=lower;
     printf("fahrenheit-celsius table\n"); 
     while (fahr<=upper){
           celsius=5*(fahr-32)/9;
           printf("%d\t%d\n",celsius,fahr);
           fahr=fahr+step;

    }
}
