#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;


void mergesorter(int *n, int low, int high);
void merger(int *n, int low, int high, int mid);

/* Merge sort */
float mergesort(int max, int order) {
    /* Variables ... */
    int high = max - 1;
    int low = 0;
    int i, j;
    int n[max];
    float start, end, seconds;

    //getting numbers for sorting...
    process();

    /* Displaying what the current sorting alg, rank, and thread count is */
    //printPosition("Merge sort", max);

    // Arrangement
    for (i = 0; i < max; i++) {
        if (order == 3) {
            n[i] = rng();
        } else if (order == 2) {
            n[i] = max - i;
        } else if (order == 1) {
            n[i] = i;
        } else if (order == 4) {
            n[i] = 1;
        }
    }

    /* Printing unsorted Merge Array */
    //cout << "Printing unsorted Merge Array ... " << endl;
    //for (int i = 0; i < max; i++) cout << n[i] << " ";
    //cout << endl;

    //sorting (timed)
    start = clock();

    /* Merge Sort*/
    mergesorter(n, low, high);
    end = clock();

    //calculating time
    seconds = (end-start)/1000000;
    //cout << "Sorting took " << seconds << " seconds to complete." << endl;

    /* Printing sorted Merge Array*/
    //cout << "Printing sorted Merge Array ... " << endl;
    //for (int i = 0; i < max; i++) cout << n[i] << " ";
    //cout << n[i] << " " << endl;

    //return findings to main
    return seconds;

}

void mergesorter(int *n, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesorter(n, low, mid);
        mergesorter(n, mid + 1, high);
        merger(n, low, high, mid);
    }
    return;
}

void merger(int *n, int low, int high, int mid) {
    int i, j, k, c[high];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (n[i] < n[j]) {
            c[k] = n[i];
            k++;
            i++;
        } else {
            c[k] = n[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = n[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = n[j];
        k++;
        j++;
    }

    for (i = low; i < k; i++) {
        n[i] = c[i];
    }
}
