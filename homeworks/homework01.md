## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.
	- Dynamic typing seems more common in the intepreted languages I've used.

2) Name two advantages of static typing over dynamic typing.
	- Static types avoid runtime errors. In a dynamically-typed language, you could have a function that's only called once a month,
	  but is called with the wrong type. With static typing, you would have caught that error a month earlier, when the code was fresh
	  in you mind.
	- Static typing is faster. You can easily allocate exactly the right amount of space for each variable, and you don't have to keep 
	  track of variable names.

3) Give an example of a static semantic error.
	- Calling this function `int add (int x, int y)` like this `add(1.0, 2.0)` would give an error.

4) What are two reasons you might want to turn off code optimization?
	- So that your bugs will be solely from your own code and not from the compiler
	- To better understand the optimization process itself by looking at un-optimized code.

5) When you run `gcc` with `-S`, why might the results look different on different computers?
	- Different computers might have different assembly language standards based on their processors

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages 
you get might look very different.  Why?
	- Variable names are syntax errors, which are handled in the compiler, while function names are handled by the linker

7) What is a segmentation fault?
	- Trying to access the wrong location in memory. I'm not sure where this would come from yet; maybe if you're directly addressing
	  memory in your program?


My questions:
 - What is the distinction between preprocessing and linking? Does preprocessing not just put the functions you want into your programs?
   If I don't use the right `include`, I won't be able to use printf, despite the fact that linking is still happening. Or is linking
   solely within the program?