## Homework 3

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bits are needed to specify a letter?

- You would need 6 bits, so you have 64 options.

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

- 2^32 ≈ 10^9, so roughly a billion. Exactly, it's 4294967296 characters.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

- "Memory" is random-access and volatile, while "storage" is longer term; it stays the same after the computer is shut off.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

- They're slightly different. A GB is 1000^3, while a GiB is 1024^3. A GiB is 2.4% larger than a GB

5) How does the virtual memory system help isolate processes from each other?

- There's a central control that tells processes where to store their variables and code. In that way, no process has to worry about where other processes storing their information.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

- The code and the constants are not going to grow. The stack and heap are what gets dynamically updated.

7) What Python data structure would you use to represent a sparse array?

- Dictionary/hash table

8) What is a context switch?

- The way that the operating system switches which process it's currently executing.