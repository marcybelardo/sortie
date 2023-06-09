#include <stdio.h>

#include "minunit.h"
#include "merge.h"
#include "quick.h"

int tests_run = 0;

static char *test_merge()
{
    double test[] = {3, 2, 1};
    mergesort(test, 3); 
    mu_assert("Merge sort failed.", (test[0] == 1 && test[1] == 2 && test[2] == 3));
    return 0;
}

static char *test_quick()
{
    double test[] = {3, 2, 1};
    quicksort(test, 0, 2);
    mu_assert("Quicksort failed.", (test[0] == 1 && test[1] == 2 && test[2] == 3));
    return 0;
}

static char *all_tests()
{
    mu_run_test(test_merge);
    mu_run_test(test_quick);
    return 0;
}

int main(int argc, char **argv)
{
    char *result = all_tests();
    if (result != 0) {
        printf("FAIL: %s\n", result);
    } else {
        printf("ALL TESTS PASSED!\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

