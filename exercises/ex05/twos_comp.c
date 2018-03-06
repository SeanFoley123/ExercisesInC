#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str = "hello ABZDthere";
	printf("%c\n", 122);
	for (int i = 0; i<strlen(str); i++) {
		if (((str[i] > 64) && (str[i]<91)) || ((str[i] > 96) && (str[i]<123))){
			printf("%c", (str[i]^32));
		}
		else {
			printf("%c", (str[i]));	
		}
	}
	// int x = 12;
	// printf("%i\n", (x^0xFFFFFFFF) + 1);
	return 0;
}
