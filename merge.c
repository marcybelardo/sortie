#include <stdlib.h>
#include "merge.h"

void merge(double* arr, double* left, int left_size, double* right, int right_size)
{
    int i = 0;
    int l = 0;
    int r = 0;
    
    while (l < left_size && r < right_size) {
        if (left[l] < right[r]) {
            arr[i++] = left[l++];
        } else {
            arr[i++] = right[r++];
        }
    }
    while (l < left_size) {
        arr[i++] = left[l++];
    }
    while (r < right_size) {
        arr[i++] = right[r++];
    }
}

void mergesort(double* arr, int size)
{
    int mid;
    int i;

    double *left;
    double *right;

    if (size < 2) {
        return;
    }

    mid = size / 2;

    left = (double*)malloc(mid * sizeof(double));
    right = (double*)malloc((size - mid) * sizeof(double));

    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergesort(left, mid);
    mergesort(right, size - mid);    
    merge(arr, left, mid, right, size - mid);
    free(left);
    free(right);
}

