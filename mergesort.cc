#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;


void sorter(int *n, int lowend, int highend);
void mergeArrays(int *n, int lowend, int highend, int middle);

/* Merge sort */
float mergesort(int max, int order, int display) {
    
    /* Variables ... */
    int highend = max - 1, lowend = 0, i;
    int n[max];
    float start, end, seconds;

    //getting numbers for sorting...
    process();

    /* Displaying what the current sorting alg, rank, and thread count is */
    if (display ==1) {
        printPosition("Merge sort", max);
    }

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
    if (display ==1) {
        cout << "Printing unsorted Merge Array ... " << endl;
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //sorting (timed)
    start = clock();

    /* Merge Sort*/
    sorter(n, lowend, highend);
    end = clock();

    //calculating time
    seconds = (end-start)/1000000;
    
    if (display ==1) {
        cout << "Sorting took " << seconds << " seconds to complete." << endl; //printing sorting time
        cout << "Printing sorted Merge Array ... " << endl; /* Printing sorted Merge Array*/
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //return findings to main
    return seconds;

}

/* Sorts the array */
void sorter(int *n, int lowend, int highend) {
    int middle;
    if (lowend < highend) {
        middle = (lowend + highend) / 2;
        sorter(n, lowend, middle);
        sorter(n, middle + 1, highend);
        mergeArrays(n, lowend, highend, middle);
    }
    return;
}

/* Merges the arrays*/
void mergeArrays(int *n, int lowend, int highend, int middle) {
    int temp[highend], lowN = lowend, lowTEMP = lowend, midN = middle + 1; //test
    while (lowN <= middle && midN <= highend) {
        if (n[lowN] < n[midN]) {
            temp[lowTEMP] = n[lowN];
            lowTEMP++;
            lowN++;
        } else {
            temp[lowTEMP] = n[midN];
            lowTEMP++;
            midN++;
        }
    }
    while (lowN <= middle) {
        temp[lowTEMP] = n[lowN];
        lowTEMP++;
        lowN++;
    }
    while (midN <= highend) {
        temp[lowTEMP] = n[midN];
        lowTEMP++;
        midN++;
    }

    for (lowN = lowend; lowN < lowTEMP; lowN++) {
        n[lowN] = temp[lowN];
    }
}
