## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

- The threads run the same code, doing different things. You need the stacks to be separate so one thread's operations don't interfere with another thread's.

2) What does the gcc flag `-lpthread` do?

- It compiles your code with the pthread library available.

3) What does the argument of `pthread_exit` do?

- You give it a pointer to a return value, so if you want to return something from the thread, you can.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

- If you do it well, nothing will go wrong. If you don't do it well, something else will try to join the thread you've already joined, and you'll most likely get a runtime error.

5) What goes wrong if several threads try to increment a shared integer at the same time?

- Incrementing a value is not an atomic operation. Therefore, you have the potential for this chain of events, where val is initialized to 0:
  - Thread A reads val = 0
  - Thread B reads val = 0 
  - Thread A increments val to 1
  - Thread B increments val to 1
- And that's not what you want.

6) What does it mean to "lock a mutex"?

- When you've locked the mutex, you've said "I'm editing this data structure right now. No one else can access it until I unlock the mutex."