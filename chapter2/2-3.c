#include<stdio.h>
/*Write a function htoi(s) , which converts a string of hexadecimal digits
(including an optional 0x or 0X ) into its equivalent integer value. The allowable digits are 0
through 9 , a through f , and A through F .*/
#include<math.h>
#define lim 4
int getline1(void);
int htoi(void);
main()
{
     int p;
     printf("enter a string of hexa decimal digits\n");
     getline1();
     p=htoi();
     printf("decimal value=%d",p);
}   
int getline1(void)
{   
     int c,i;
     char s[lim];
     for (i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
         s[i]=c;
         s[i]='\0';
     return i;
}

int htoi(void)
{
     int l,i,d,a;
     a=0;
     char s[lim];
     for(i=0;s[i]!='\0';++i){
        if(s[i]>='0'&& s[i]<='9')
          d=(s[i]-'0');
        else if(s[i]>='a'&& s[i]<='f')
               d=(s[i]-'a'+10);
        else if(s[i]>='A'&& s[i]<='F')
               d=(s[i]-'A'+10);
        a=16*a+d;
     }  
     return a;
}  

        
 
              




