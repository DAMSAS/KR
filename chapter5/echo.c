#include<stdio.h>
main(int argc,char *argv[])
{
    while (--argc)
          printf("%s%s",*++argv,(argc>1)?" ":"");
          printf("\n");
    return 0;
}
