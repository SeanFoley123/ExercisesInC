/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

int main ()
{
    int var2 = 5;
<<<<<<< HEAD
    int var3 = 6;
    int var4 = 7;
    void *p = malloc(57);
    void *q = malloc(57);
    char *s = "Literal string";
=======
    void *p = malloc(128);
    char *s = "Hello, World";
>>>>>>> f1730219000dea2729d3a9625259830250492bea

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
<<<<<<< HEAD
    printf ("Address of var3 is %p\n", &var3);
    printf ("Address of var4 is %p\n", &var4);
    printf ("Address of p is %p\n", p);
    printf ("Address of q is %p\n", q);
    printf ("Address of s is %p\n", s);
=======
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);
>>>>>>> f1730219000dea2729d3a9625259830250492bea

    return 0;
}
/* Questions: Does malloc allocate memory in the 
stack? That seems like it would make the most sense
*/