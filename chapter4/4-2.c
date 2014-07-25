#include<stdio.h>
/*Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.*/
#define lim 50
int getline1(void);
double atof(void);
int i,c,n,sign;
double k,val,power;
char s[lim];
main()
{   
     extern  double k;
     extern char s[lim];
     printf("enter a string\n");
     getline1();
     printf("line entered=%s\n",s);
     k=atof();
     printf("value =%f\n",k);
}
int getline1(void)
{
    extern int c,i;
    extern char s[lim];
    for (i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
        s[i]=c;
        s[i]='\0';
    
}
double atof(void)
{
    double val,power;
    int i,e,sign;
    extern char s[lim];
    for (i=0;isspace(s[i]);++i)
         ;
    sign = (s[i]=='-')?-1:1;
    if ( s[i]=='+'||s[i]=='-')
       i++;
    for (val=0.0;isdigit(s[i]);i++)
       val=10.0*val+(s[i]-'0');
    if (s[i]=='.')
       i++;
    for (power=1.0;isdigit(s[i]);i++){
        val=10.0*val+(s[i]-'0');
        power*=10;
    }
   val = sign*val/power;
   if (s[i]=='e' || s[i]=='E'){
      i++;
      sign=(s[i]=='-')?-1:1;
      if (s[i]=='-' || s[i]=='+')
         i++;
      for (e=0;isdigit(s[i]);++i)
          e=10*e+(s[i]-'0');
      if (sign==1)
         for (;e>0;--e)
             val*=10;
      else
         for (;e>0;--e)
             val/=10;
   }
   return val;
}
               
      



    
    
    
