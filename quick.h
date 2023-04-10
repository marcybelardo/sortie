#ifndef QUICK_H
#define QUICK_H
// Functions for quicksort algorithm

// Partition array into subarrays, returns index of pivot
int partition(double *arr, int lo, int hi);

// Recursive quicksort function
void quicksort(double *arr, int lo, int hi);

#endif
