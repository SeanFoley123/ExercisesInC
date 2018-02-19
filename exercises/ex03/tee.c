// This code takes stdin, sends it to stdout, and also sends the input stream to any number of 
// specified files.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <signal.h>

// Function that redirects interrupt handling; credit goes to https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
void interrupt_handler(int signum){}

int main (int argc, char *argv[]) {

	// Set the max size of all strings used in the program
	int str_buffer_size = 100;

	// General setting; can be changed w/ command line options
	char *read_write_mode = "w";

	FILE *help_file = fopen("./help_file.txt", "r");
	char help_string[str_buffer_size];

	// This struct tranlates longform options to their equivalents
	static struct option long_options[] = {
		{"append", no_argument, NULL, 'a'},
		{"ignore-interrupts", no_argument, NULL, 'i'},
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'v'},
		{0, 0, 0, 0}
	};

	// Now parse all the options, and change settings accordingly
	char option_character;
	while ((option_character = getopt_long(argc, argv, "aihv", long_options, NULL)) != -1) {
		switch (option_character) {
			case 'a':
				read_write_mode = "a";
				break;
			case 'i':
				signal(SIGINT, interrupt_handler);
				break;
			case 'h':
				while (fgets(help_string, str_buffer_size, help_file) != NULL) {
					fprintf(stdout, "%s", help_string);
				}
				exit(0);
			case 'v':
				puts("Version 1.0");
				puts("Sean did this");
				exit(0);
		}
	}

	// These two lines let subsequent code only parse the arguments, not the options
	argc -= optind;
	argv += optind;

	// Open all the files selected by the user
	FILE *output_files[argc];
	for (int i=0; i<argc; i++) {
		output_files[i] = fopen(argv[i], read_write_mode);
	}

	// Read from the input until the user enters CTRL-D, and print it to both stdout and open files
	char input[str_buffer_size];
	while (fgets(input, str_buffer_size, stdin) != NULL) {
		fprintf(stdout, "%s", input);
		for (int i=0; i<argc; i++){
			fprintf(output_files[i], "%s", input);
		}
	}

	for (int i=0; i<argc; i++){
		fclose(output_files[i]);
	}

	return 0;
}

/* Reflection:
The way I made this code was by building small chunks. I first implemented
the basic echoing to a file. Then I made a separate file called getopt_experiment to perfect a 
system for catching command line options. Next I copied that code over to the echo/file writer,
and integrated the two. Finally, I filled in the switch statements with the special behaviors 
I wanted.
This system worked quite well; I really didn't run into any roadblocks. When I got stuck, I'd
check stackoverflow, a man page, or head first C. 

Comparison: There was a lot of syntax I didn't understand in the professional implementation.
It was interesting how they made sure to add the stdout just like a file; that was a clever way 
to eliminate some redundant code I had. 
I don't understand the for loop on line 107 at all, but I hope to at some point.
The error messages were kind of garbage, though. Single word messages with no context.
*/
