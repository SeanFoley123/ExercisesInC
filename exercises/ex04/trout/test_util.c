#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "trout.h"
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test() {
    char *res = icmpcode_v4(5);
    char *message = "test failed: icmpcode_v4(5) should return \"source route failed\"";
    mu_assert(message, strstr("source route failed", res));
    return NULL;
}

static char * all_tests() {
    mu_run_test(test);
    return NULL;
}

int main() {
	char *result = all_tests();
	if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    return result != 0;
}