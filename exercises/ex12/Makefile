
counter: counter.c
	gcc -Wall -o counter counter.c -lpthread

counter_array: counter_array.c
	gcc -Wall -o counter_array counter_array.c -lpthread

counter_mutex: counter_mutex.c mutex.h mutex.c
	gcc -Wall -o counter_mutex counter_mutex.c mutex.c -lpthread

counter_array_mutex: counter_array_mutex.c mutex.c mutex.h
	gcc -Wall -o counter_array_mutex counter_array_mutex.c mutex.c -lpthread