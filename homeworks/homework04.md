## Homework 4

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

- File systems abstract away the separation of memory and storage, and make it so programmers only have to interact with predictable streams of bytes. For instance, when you save a file, you expect that file is now changed on the drive the file system shows it in. But in fact, your changes could easily be sitting in a cache somewhere waiting to be sent. 

2) What information do you imagine is stored in an `OpenFileTableEntry`?

- I'd expect it to contain a pointer to where we are in the memory, and information about the addresses of the data contained in that file. Maybe a pointer to the next inode entry?

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

- It's very stingy about when to do IO requests to storage. For instance, if you write a change to a block on persistent storage, it will queue that change up and wait until you're done messing with that block to actually send it.
- It does a lot of caching, so holding things it expects to use again in memory, which has much lower overhead.

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

- The save file command takes a lot of time. It was probably put in line to execute, but he much faster print command was executed first (in addition to a lot of commands from a lot of other processes). Then, before the processor got around to actually saving the file, power cut out, and everything in memory was eliminated.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

- An advantage of a FAT Is that you don't have predefined cluster sizes. With inodes, if you have a tiny file, you still spend blocks on indirection, double indirection, and triple indirection. That could also be a disadvantage; I imagine knowing beforehand what size data structure you're approaching could help design optimizations.

6) What is overhead?  What is fragmentation?

- Overhead: The amount of storage required to keep track of which blocks are used by whom.
- Fragmentation: The number of unused or partially used blocks.
  - Question: if you have 1 GiB of space but only 1 MiB of stuff, how can you keep down fragmentation? There'll be unused space because you just don't need that space.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

- There are a lot of things that make a lot of sense in a file abstraction. For instance, it make a lot of sense to open a socket and write to it. I actually can't think of any downsides right now.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).



