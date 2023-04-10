#ifndef MERGE_H
#define MERGE_H

// Functions for merge sort algorithm

// Merge two arrays into the main array
void merge(double* arr, double* left, int left_size, double* right, int right_size);

// Recursive division of array for sorting
void mergesort(double* arr, int size);

#endif
