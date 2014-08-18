/*Write a recursive version of the function reverse(s) , which reverses the
string s in place.*/
#include <stdio.h>
#include <string.h>
void reverse(char s[],int k);
int i = 0;
main()
{
	int k, i, j;
	char s[50];
	printf("Enter a string\n");
	gets(s);
	k = strlen(s)-1;
	reverse(s,k);
	printf("reversed form =%s\n",s);
}
void reverse(char s[], int k)
{
	int c;
	extern int i;
	if (k  > 0) {
		c=s[i],s[i]=s[k],s[k]=c;
                i++;
                k--;
		reverse(s,k);
	}
	return;
}

		
	

