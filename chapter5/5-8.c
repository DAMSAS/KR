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
     int i,leap;
     leap = year%4 ==0 && year%100 !=0 || year%400 == 0;
     if (month < 1 || month > 12)
        return -1;
     if (day < 1 || daytab[leap][month])
        return -1;
     for (i=1;i<month;i++)
         day+=daytab[leap][i];
     return day;
}
void month_day(int year,int yearday,int *pmonth,int *pday)
{
     int i,leap;
     if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
     }
     leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
     for (i = 1;yearday>daytab[leap][i];i++)
         yearday-=daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
}
    
           
     
    
