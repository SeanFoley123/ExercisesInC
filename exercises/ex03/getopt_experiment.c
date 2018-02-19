#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>

int main (int argc, char *argv[])
{
	char ch;
	static struct option long_options[] = {
		{"absalom", no_argument, NULL, 'a'},
		{"excellent-tuna", no_argument, NULL, 'e'},
		{0, 0, 0, 0}
	};
	while ((ch = getopt_long(argc, argv, "ae", long_options, NULL)) != -1) {
		switch (ch) {
			case 'a':
				puts("It's a");
				break;
			case 'e':
				puts("Nice try guy");
				break;
		}
	}
	return 0;
}