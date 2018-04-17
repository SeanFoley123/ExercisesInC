## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

- Threads can access the data structure concurrently without causing bad behavior.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

- So that you can make your own errors instead of getting segfaults.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

- Child 1 reads counter - it's not at the end
- Child 2 reads the counter, increments the array, and increments the counter
- Child 1 now tries to increment the array - but since Child 2 incremented the counter, we're now past the end of the array! Anything could happen!

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

- If you didn't, the mutex would be blocked, nothing would change, and you'd never get out of your wait.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

- We know for sure the mutex is locked
- We believe our condition is true

6) What happens if you signal a condition variable when there are no waiting threads?

- Nothin

7) Do you have to lock the mutex to signal a condition variable?

- No, but you should make sure to unlock it, or the thing you're signaling will never execute.	

8) Does the condition have to be true when you signal a condition variable?

- Not in the slightest




