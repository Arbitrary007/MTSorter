#ifndef SORTERS_H
#define SORTERS_H
#include <omp.h>
#include <iostream>
#include <fstream>

//bubble sort
float bubble(int max, int order);

/* counting sort */
float counting(int max, int order);

//heap sorter
float heapsort(int max, int order);

//insertion sort
float insertion(int max, int order);

/* merge sort */
float mergesort(int max, int order);

//quicksorter
float quicksort(int max, int order);

/* radix sort */
float radixsort(int max, int order);

//selection sort
float selection(int max, int order);

#endif
