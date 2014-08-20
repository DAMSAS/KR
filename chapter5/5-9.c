#include<stdio.h>
static char daytab[2] [13]={
            {0,31,28,31,30,31,30,31,31,30,31,30,31},
            {0,31,29,31,30,31,30,31,31,30,31,30,31}
     };
int day_of_year(int year,int month,int day);
void month_day(int year,int yearday,int *pmonth,int *pday);
main()
{    
     int c,i,y,m,d;
     printf("select any of the following options:a day of year,b month day\n");
     switch (c=getchar()) {
     case 'a':
           printf("enter year,month and day\n");
           scanf("%d%d%d",&y,&m,&d);
           i = day_of_year(y,m,d);
           printf("day of year =%d\n",i);
           break;
     case 'b':
           printf("enter year and yearday\n");
           scanf("%d%d",&y,&d);
           month_day(y,d,&m,&i);
           printf("month =%d\n day =%d\n",m,i);
           break;
     }
}
int day_of_year(int year,int month,int day)
{    
     int leap;
     char *p;
     leap = year%4 ==0 && year%100 !=0 || year%400 == 0;
     p = daytab[leap];
     while (--month)
           day+=*++p;
     return day;
}
void month_day(int year,int yearday,int *pmonth,int *pday)
{
     int leap;
     char *p;
     leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
     p = daytab[leap];
     while (yearday > *++p)
           yearday-=*p;
        *pmonth = p-*(daytab+leap);
        *pday = yearday;
}
    
           
     
    
