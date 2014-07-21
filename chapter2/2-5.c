#include<stdio.h>
/*Write the function any(s1,s2) , which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2 .
(The standard library function strpbrk does the same job but returns a pointer to the
location.)*/
#define lim 2000
int getline1(void);
int getline2(void);
char s1[lim],s2[lim];
int any(void);
main()
{
	extern char s1[lim],s2[lim];
        int l;
        printf("enter first line\n");
        getline1();
        printf("enter second line\n");
        getline2();
        printf("line1:%s\n",s1);
        printf("line2:%s\n",s2);
        l=any();
        printf("position=%d\n",l);
        
        
        
       
}
int getline1(void)
{
       int i,c;
       extern char s1[lim];
       for (i=0;i<lim-1&&(c=getchar())!=EOF && c!='\n';++i)
       	    s1[i]=c;
            s1[i]='\0';
         
}
 int getline2(void)
{
       int i,c;
       extern char s2[lim];
       for (i=0;i<lim-1&&(c=getchar())!=EOF && c!='\n';++i)
       	   s2[i]=c;
           s2[i]='\0';
         
}
int any(void) 
{
      int i,k;
      int p;
      extern char s1[lim],s2[lim];
      p=-1;
      for (k=0; p==-1 && s1[k] !='\0';++k){
          for (i=0;p==-1 && s2[i] !='\0';++i){
               if(s1[k]=s2[i]){
                  p=k;
                  
                  
                }
           }
        }
     
         return p;      
 
      
}
    
                
          
      
      
      
           
     
