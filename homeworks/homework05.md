## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

You'll take that leftmost bit, which is a one, and treat it as the sign of the number. Then you'll extend that sign into all the new bits, and suddenly have 65408 (1111 1111 1000 000) instead of 128 (0000 0000 1000 000).

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

`printf("%i\n", (x^0xFFFFFFFF) + 1);`

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

I've thought about it, and I really have no idea.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

b1100 0001 0101 0000 0000 0000 0000 0000

As an int, I'm guessing you would interpret the first 4 bytes, so you'd get 49488.

That's not actually how it worked out. I'm getting pretty confused by the fact that ints claim to be 4 bytes, but actually seem to take up 8 bytes. What really happens is it interprets this as 2's complement, so you get -1051721728.

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

```c
for (int i = 0; i<strlen(str); i++) {	if (((str[i] > 64) && (str[i]<91)) || ((str[i] > 96) && (str[i]<123))){
		printf("%c", (str[i]^32));
	}
	else {
		printf("%c", (str[i]));	
	}
}
```