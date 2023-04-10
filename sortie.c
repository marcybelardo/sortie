#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "merge.h"
#include "quick.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr,
                "USAGE: sortie [ALGORITHM] FILENAME\n-m\tMerge Sort\n-q\tQuick Sort\n");
        return 1;
    }

    int c;
    double num;
    double numbers[5000];
    FILE *fptr;
    char* filename = argv[2];

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 2;
    }

    for (int i = 0; i < 5000; i++) {
        fscanf(fptr, "%lf", &num);
        numbers[i] = num;
    }

    fclose(fptr);
    
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    while ((c = getopt(argc, argv, "mq")) != -1) {
        switch (c) {
            case 'm':
                mergesort(numbers, size);
                break;
            case 'q':
                quicksort(numbers, 0, size - 1);
                break;
            case '?':
                if (isprint (optopt)) {
                    fprintf(stderr,
                            "Unknown option -%c.\n", optopt);
                } else {
                    fprintf(stderr,
                            "Unknown character1 '\\x%x'.\n",
                            optopt);
                }
                return 3;
            default:
                abort();
        }
    }

    for (int j = 0; j < size; j++) {
        printf("m = %.02f\n", numbers[j]);
    }

    return 0;
}
