/*Run the `` hello, world '' program on your system. Experiment with leaving
out parts of the program, to see what error messages you get.*/
#include<stdio.h> 
main()
{
     printf("hello, world\n);
}

/* output:

ex1.c: In function ‘main’:
ex1.c:6:9: warning: missing terminating " character [enabled by default]
  printf("hello, worl\n);
         ^
ex1.c:6:2: error: missing terminating " character
  printf("hello, worl\n);
  ^
ex1.c:7:1: error: expected expression before ‘}’ token
 }
 ^
ex1.c:7:1: error: expected ‘;’ before ‘}’ token
*/
