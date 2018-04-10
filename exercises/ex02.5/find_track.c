/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

void print_error(int error_code, regex_t* regex_p) {
    char error_message[100];
    regerror(error_code, regex_p, error_message, sizeof(error_message));
    printf("ERROR: %s\n", error_message);
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
int find_track_regex(char pattern[])
{
    // This funcion which tracks match a regex
    // This was helpful: http://web.archive.org/web/20160308115653/http://peope.net/old/regex.html
    regex_t regex;
    int return_code;
    return_code = regcomp(&regex, pattern, REG_NOSUB);
    if (return_code != 0) {
        print_error(return_code, &regex);
        return 1;
    }

    int found_match = 0;

    for (int i=0; i<NUM_TRACKS; i++) {
        return_code = regexec(&regex, tracks[i], 0, NULL, 0);
        if (return_code == 0) {
            printf("%s\n", tracks[i]);
            found_match = 1;
        }
        else if (return_code == REG_NOMATCH) {
            continue;
        }
        else {
            print_error(return_code, &regex);
            return 1;
        }
    }
    if (!found_match) {
        puts("No match found.");
    }
    regfree(&regex)
    return 0;
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char* fgets_return;
    char search_for[80];

    do {
        /* take input from the user and search */
        printf("Search for: ");
        fgets_return = fgets(search_for, 80, stdin);
        rstrip(search_for);

        // find_track(search_for);
        find_track_regex(search_for);
    }
    while (fgets_return != NULL);

    return 0;
}
