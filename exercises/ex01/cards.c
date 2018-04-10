/* This program keeps track of the current count in a game of cards.
*/

#include <stdio.h>
#include <stdlib.h>

int name_to_number(char *card_name) {
	/* This function just translates a card into a value. */
	int card_value;
	switch (card_name[0]) {
		case 'K':
	    case 'Q':
	    case 'J':
	    	return 10;
	    case 'A':
	    	return 11;
	    case 'X':
	    	return -999;
	    default:
	    	card_value = atoi(card_name);
	    	if ((card_value < 1)||(card_value>10)) {
	    		puts("I don't get it!");
	    	}
	    	return card_value;
    }
}

int update_count(int card_value) {
	/* This function determines how to adjust the count. I wanted to do it with a static int,
	but I was having issues with using variables and functions before they're defined. */
	if ((card_value > 2) && (card_value < 7)) {
		return 1;
	}
	else if (card_value==10) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	/* This function just runs the loop and keeps track of the values. */
	char card_name[3];
	int count = 0;
	int card_value;
	do {
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		card_value = name_to_number(card_name);
		if (card_value == -999) {
			continue;
		}
		count += update_count(card_value);
		printf("Current count: %i\n", count);
	} while (card_name[0] != 'X');
	return 0;
}