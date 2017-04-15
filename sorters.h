#ifndef SORTERS_H
#define SORTERS_H
#include <omp.h>
#include <iostream>
#include <fstream>

//bubble sort
float bubble(int max, int order, int display);

/* counting sort */
float counting(int max, int order, int display);

//heap sorter
float heapsort(int max, int order, int display);

//insertion sort
float insertion(int max, int order, int display);

/* merge sort */
float mergesort(int max, int order, int display);

//quicksorter
float quicksort(int max, int order, int display);

/* radix sort */
float radixsort(int max, int order, int display);

//selection sort
float selection(int max, int order, int display);

#endif
