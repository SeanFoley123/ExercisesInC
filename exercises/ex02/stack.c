/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];
    // This array is created on the stack

    printf("%p\n", array);
    //You're printing the address on the stack

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
    //After this return, the stack gets cleared and
    //the pointer is meaningless
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    /* I'm not sure where exactly in this function the
    seg fault happens; my guess would be in the print
    statement. I need to learn gdb better so it will
    give me line numbers for the errors instead of hex
    addresses. */
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
