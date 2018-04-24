## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/SeanFoley123/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

- Each time you pass it to a function, you're actually passing a copy of the semaphore - so the threads that are supposed to be sharing a semaphore are actually all looking at different ones.

2) When you use a Semaphore as a mutex, what should its initial value be?

- I think you'd start it at 1. Locking the mutex would be decrementing, and unlocking would be incrementing. I'm not at all confident in this, though.

3) Can you think of another use for a Semaphore where you might use a different initial value?

- I'm still wrapping my head around the semaphores at all - I'll come back to this once (if) I understand semaphores

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

- It means you could push three new items onto the queue until you have to wait.

5) What does it mean if `queue->spaces` is `-3`?

- There are currently three threads waiting in line to push something onto the queue.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

- Because it's waiting on items; that will only unblock the thread when there's actually an item put in the queue.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

- By making a semaphore w/mutexes and condition variables

8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

- When you signal a semaphore, another thread needs to become active. This gives every thread a chance to play.