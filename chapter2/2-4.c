#include<stdio.h>
/*Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2 .*/
#define lim 20
int getline1(void);
int getline2(void);
int i,j,c,k;
char s1[lim],s2[lim];
void squeeze(void);
main()
{
	extern char s1[],s2[];
        printf("enter first line\n");
        getline1();
        printf("enter second line\n");
        getline2();
        printf("line1:%s\n",s1);
        printf("line2:%s\n",s2);
        squeeze();
       
}
int getline1(void)
{
       extern int i,c;
       extern char s1[];
       for (i=0;i<lim-1&&(c=getchar())!=EOF && c!='\n';++i)
       	    s1[i]=c;
            s1[i]='\0';
         
}
 int getline2(void)
{
       extern int i,c;
       extern char s2[];
       for (i=0;i<lim-1&&(c=getchar())!=EOF && c!='\n';++i)
       	   s2[i]=c;
           s2[i]='\0';
         
}
void squeeze(void)
{
      extern int i,j,k;
      extern char s1[],s2[];
      for (k=0;s2[k]!='\0';++k){
          for (i=j=0;s1[i]!='\0';++i)
              if(s1[i]!=s2[k])
                s1[j++]=s1[i];
                
          s1[j]='\0';
      }

      printf("modified line 1:%s\n",s1);
}
           
     
