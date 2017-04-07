#ifndef SORTERS_H
#define SORTERS_H
#include <omp.h>

//bubble sort
void bubble(int max, int order);

/* counting sort */
void counting(int max, int order);

//heap sorter
void heapsort(int max, int order);

//insertion sort
void insertion(int max, int order);

/* merge sort */
void mergesort(int max, int order);

//quicksorter
void quicksort(int max, int order);

/* radix sort */
void radixsort(int max, int order);

//selection sort
void selection(int max, int order);

#endif

