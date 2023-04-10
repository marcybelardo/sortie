#include <stdlib.h>
#include "quick.h"

int partition(double *arr, int lo, int hi) 
{
    int i = lo - 1;
    double pivot = arr[hi];

    for (int j = lo; j <= hi - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            double tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    i++;
    double tmp = arr[i];
    arr[i] = arr[hi];
    arr[hi] = tmp;
    
    return i;
}

void quicksort(double *arr, int lo, int hi) 
{
    if (hi <= lo) {
        return;
    }

    int pivot = partition(arr, lo, hi);

    quicksort(arr, lo, pivot - 1);
    quicksort(arr, pivot + 1, hi);
}

