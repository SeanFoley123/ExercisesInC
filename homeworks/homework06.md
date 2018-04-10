## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

- I'd expect malloc and free to be constant time, while calloc and especially realloc should be proportional to size.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

​	You could get garbage results, or seg fault if you hit a section that can't be read

b) Writing to unallocated memory.

​	You could seg fault, or have your data written over when that chunk is later allocated

c) Reading from a freed chunk.

​	It could have been written over int he meantime

d) Writing to a freed chunk.

​	You could literally die

e) Failing to free a chunk that is no longer needed.

​	You could run out of memory


3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

​	Firefox has the top three processes. Whew. My markdown editor is up there, and the window system, 		XORG, is pretty bad.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

​	It is not space efficient, and it might slow down Malloc as well. You could put all your little things into bigger arrays, and then allocate space for those arrays on the heap.	

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
