#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;

//My test bubble sorter.

float bubble(int max, int order, int display) {

    //Declaring variables...

    int i, j;
    int n[max];
    float start, end, seconds;

    //getting numbers for sorting... setting seed

    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    if (display == 1) {
        printPosition("Bubble Sort", max);
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

    /* Printing unsorted Bubble Array */
    if (display == 1) {
        cout << "Printing unsorted Bubble Array ... " << endl;
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //sorting (timed)
    start = clock();

    for (j = 0; j < max; j++) {
        for (i = 0; i < max - 1; i++) {
            if (n[i] > n[i + 1]) {
                swap(&(n[i]), &(n[i + 1]));
            }
        }
    }

    end = clock();

    //calculating time

    seconds = (end - start) / 1000000;

    if (display == 1) {
        cout << "Sorting took " << seconds << " seconds to complete." << endl; //printing sorting time
        cout << "Printing sorted Bubble Array ... " << endl; /* Printing sorted Bubble Array */
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //return findings to main
    return seconds;

}
