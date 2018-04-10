
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>

int main(int argc, char** argv) {
	char *num_as_str;
	int num;
	char * num_to_str[100];
	char word[100];
	GHashTable* word_counts = g_hash_table_new(g_str_hash, g_str_equal);
    FILE *book = fopen("egypt.txt", "r");    
    while ((fscanf(book, "%s", word)) != EOF) {    
    	char *num_as_str = g_hash_table_lookup(word_counts, word);
    	printf("%s\n", num_as_str);
    	if (strcmp(num_as_str, "(null)")) {
    		num = 0;
    	}
    	else {
    		num = atoi(num_as_str);
    	}
    	g_hash_table_insert(word_counts, word, "1");
	}
    return 0;
}