/*Define a macro swap(t,x,y) that interchanges two arguments of type t .*/
#include<stdio.h>
#define swap(t,x,y) { t z;\
                      z=x,x=y,y=z;}
main()
{   int x,y;
    printf("enter two values\n");
    scanf("%d%d",&x,&y);
    printf("x=%d y=%d\n",x,y);
    swap(int,x,y);
    printf("values after swap operation: x=%d y=%d\n",x,y);
}
    
