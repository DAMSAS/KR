#include<stdio.h>
/*Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.*/
int binsearch(int x, int v[100], int n);
main()
{     int n,i,j,v[100],p,x;
      printf("enter upper limit\n");
      scanf("%d",&n);
      printf("enter number\n");
      scanf("%d",&x);
      i=j=0;
      j=n;
      while (j>0){
            v[i]=i;
            ++i;
            --j;
      }
      j=n;
      printf("digits=\n");
      for (i=0;i<j;++i)
      printf("%d",v[i]);
      printf("\n");
      p=binsearch(x,v,n);
      printf("position=%d\n",p);
      
      
}

int binsearch(int x, int v[100], int n)
{
     int low, high, mid,j;
     j=n;
     low = 0;
     high = j-1;
     mid = (low+high)/2;
     while (low <= high && x!=v[mid]) {
           if (x > v[mid])
              low = mid+1;
           else 
              high = mid - 1;
           mid = (low+high)/2;
     }
     if(x==v[mid])
       return mid;
     else
       return -1;

}
   
    
