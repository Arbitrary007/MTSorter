#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;

/* Radix sorter */
float radixsort(int max, int order) {
    /* Variables... */
    int i, j;
    int n[max];
    float start, end, seconds;

    //getting numbers for sorting...
    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    //printPosition("radix sort", max);

    //Arrangement
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

    /* Printing unsorted Radix Array */
    //cout << "Printing unsorted Radix Array ... " << endl;
    //for (int i = 0; i < max; i++) cout << n[i] << " ";
    //cout << endl;

    //sorting (timed)
    start = clock();

    /* Radix Sort */
    int maxNumber = n[0];
    for (i = 1; i < max; i++) {
        if (n[i] > maxNumber)
            maxNumber = n[i];
    }
    int exp = 1;
    int *tmpBuffer = new int[max];
    while (maxNumber / exp > 0) {
        int decimalBucket[10] = {0};
        for (i = 0; i < max; i++) decimalBucket[n[i] / exp % 10]++;
        for (i = 1; i < 10; i++) decimalBucket[i] += decimalBucket[i - 1];
        for (i = max - 1; i >= 0; i--) tmpBuffer[--decimalBucket[n[i] / exp % 10]] = n[i];
        for (i = 0; i < max; i++) n[i] = tmpBuffer[i];
        exp *= 10;
    }
    end = clock();

    // calculating time
    seconds = (end - start) / 1000000;
    //cout << "Sorting took " << seconds << " seconds to complete." << endl;

    /* Printing sorted Radix Array*/
    //cout << "Printing Radix Array ... " << endl;
    //for (int i = 0; i < max; i++) cout << n[i] << " ";
    //cout << endl;

    //return findings to main
    return seconds;

}

