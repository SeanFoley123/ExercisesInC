#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_input_size 8
#define input_buffer_size 100
#define num_array_size 12

/* This code is a simple program to input a series of numbers and find their sum
I got a lot of help from this thread:
https://www.linuxquestions.org/questions/programming-9/fgets-and-buffer-overflow-4175467362/
*/

void prt_num_array(int current_num_array_pos, int num_array[])
{
	//This function prints a readable version of valid numbers the user has input
	printf("[");
	for (int i=0; i<(current_num_array_pos-1); i++)
	{
		printf("%i,", num_array[i]);
	}
	printf("%i]", num_array[current_num_array_pos-1]);
}

int main()
{
	char input[input_buffer_size];
	int current_num_array_pos = 0;
	int num_array[num_array_size];

	puts("Welcome to adder! Enter all your numbers and press CTRL-D to sum and exit.")
	while(fgets(input, sizeof(input), stdin) != NULL)
	{	
		//This loop terminates when the user exits stdin
		if (strlen(input) > max_input_size)
		{
			//Arbitrarily limiting numbers to 8 digits
			printf("Input can be at most %i digits.\n", (max_input_size-1));
			continue;
		}

		int current_num = atoi(input); //Converting input to a decimal
		switch (current_num)
		{
			case 0:
				if (*input != '0')
				{
					//Invalid input returns the number 0
					puts("That is not a valid number.");
					continue;
				}
				//Intentionally using fallthrough here to capture the case where the user input 0
			default:
				if ((current_num_array_pos > (num_array_size-1)))
				{
					//In the case that we've filled up the array, we can't add anything more.
					puts("That is too many numbers for my little brain. Press CTRL-D to sum and exit.");
					
				}
				else
				{
					//Otherwise, stick the input in the array and increment the position counter
					num_array[current_num_array_pos] = current_num;
					current_num_array_pos += 1;
				}
				printf("Current numbers: ");  //Give user feedback
				prt_num_array(current_num_array_pos, num_array);
				puts("");
		}
	}
	int num_sum = 0;
	for (int i=0; i<(current_num_array_pos); i++)
	{
		//Sum all the valid inputs
		num_sum += num_array[i];
	}

	printf("Sum of ");
	prt_num_array(current_num_array_pos, num_array);
	printf(" is %i\n", num_sum);
	return 0;
}