#include <stdio.h>

int main() {
	int x = 12;
	int y = x + 1;
    printf("%i\n", y);
    return 0;
}
/* Observations:
With the non-optimized code, there is no x referenced, but there is a line putting the value of x into a memory address.
When I optimized it, there were significantly more headers, but nowhere was the value of x referenced.
Then, when I changed it to print x, it suddenly started putting the number 12 into memory again, and also changed the 
call  to puts to a call to __printf_chk.
When I add y but don't turn on optimization, it shows the number 12 and an add function with the number 1.
Then when I turn on optimization, there's no 12, and just a 13; it completes the addition before runtime.
*/