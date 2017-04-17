#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;

/* Radix sorter */
float radixsort(int max, int order, int display) {
    
    /* Variables... */
    int i;
    int n[max];
    float start, end, seconds;

    //getting numbers for sorting...
    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    if (display == 1) {
        printPosition("radix sort", max);
    }

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
    if (display == 1) {
        cout << "Printing unsorted Radix Array ... " << endl;
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //sorting (timed)
    start = clock();

    /* Radix Sort */
    int currentMax = n[0];
    for (i = 1; i < max; i++) {
        if (n[i] > currentMax)
            currentMax = n[i];
    }
    int num = 1;
    int *temp = new int[max];
    while (currentMax / num > 0) {
        int store[10] = {0};
        for (i = 0; i < max; i++) store[n[i] / num % 10]++;
        for (i = 1; i < 10; i++) store[i] += store[i - 1];
        for (i = max - 1; i >= 0; i--) temp[--store[n[i] / num % 10]] = n[i];
        for (i = 0; i < max; i++) n[i] = temp[i];
        num *= 10;
    }
    
    end = clock();

    // calculating time
    seconds = (end - start) / 1000000;
    
    if (display == 1) {
        cout << "Sorting took " << seconds << " seconds to complete." << endl; //printing sorting time
        cout << "Printing Radix Array ... " << endl; /* Printing sorted Radix Array*/
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //return findings to main
    return seconds;

}

