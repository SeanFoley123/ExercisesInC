## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of 
  the ones in the book).  What is abstractly true about the system that
  is not literally true about the implementation?
  - Debit cards. It appears that you swipe the card and money is removed from your checking account much like withdrawing and
    using cash. In actuality, there's likely no transfer of physical money; just a lot of complex verifications and a change in
    account balances.

2. What is the difference between a program and a process?
  - A program is the set of instructions and data that performs a certain desired operation. A process is the virtual space
    that contains that program as it runs, and gives the similitude that the program is running continuously.

3. What is the primary purpose of the process abstraction? 
  - So that programmers have a very simple interface to the processor; they give commands, and the processor completes those
    commands as if it has nothing else to do.

4. What illusion does the process abstraction create?
  - That every process is running continuously, when really process time is stopping and starting relative to clock time.

5. What is the kernel?
  - It's the brain coordinating basic OS operations.

6. What is a daemon?
  - A process that provides an individual OS operation.

### My notes
Isolation via interaces; changes in individual code components should not affect other code components.
Process: contains the program, all the data the program is using, and information about the state of the program.
A processor can run multiple processes without the programs in those processes really caring; it just pauses time
for one process while it works on another.
Virtual memory: How does this actually work? They say it "appears" like programs have a dedicated chunk of memory;
what do they really have?
Are processes managing other processes? What is the overarching "brain" that keeps processes from running into 
each other? It must be running all the time; does it have its own dedicated chunk of memory? How does it use the
processor?
It looks like the kernel contains little daemon processes to do the work it needs. Who decides when the daemons get
to run? Other daemons?