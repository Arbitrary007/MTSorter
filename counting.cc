#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;

/* Counting sort */
float counting(int max, int order) {
    /* Variables... */
    int i, j;
    int n[max];
    float start, end, seconds;
    int b = sizeof (n) / sizeof (int);
    int max2 = n[0];

    //getting numbers for sorting...
    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    //printPosition("Counting sort", max);

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

    /* Printing unsorted Counting Array */
    //cout << "Printing unsorted Counting Array ... " << endl;
    //for (int i = 0; i < max; i++) cout << n[i] << " ";
    //cout << endl;

    //sorting (timed)
    start = clock();

    /* Counting Sort*/
    for (int i = 1; i < b; i++) {
        if (n[i] > max2) {
            max2 = n[i];
        }
    }

    int *output = new int[b];
    for (int i = 0; i < b; i++) {
        output[i] = 0;
    }
    int *temp = new int[max2 + 1];
    for (int i = 0; i < max2 + 1; i++) {
        temp[i] = 0;
    }
    for (int i = 0; i < b; i++) {
        temp[n[i]] = temp[n[i]] + 1;
    }
    for (int i = 1; i < max2 + 1; i++) {
        temp[i] = temp[i] + temp[i - 1];
    }
    for (int i = b - 1; i >= 0; i--) {
        output[temp[n[i]] - 1] = n[i];
        temp[n[i]] = temp[n[i]] - 1;
    }

    end = clock();
    //calculating time
    seconds = (end - start) / 1000000;
    //cout << "Sorting took " << seconds << " seconds to complete." << endl;

    /* Printing sorted Counting Array*/
    //cout << "Printing sorted Counting Array ... " << endl;
    //for (int i = 0; i < b; i++) cout << output[i] << " ";
    //cout << endl;

    //return findings to main
    return seconds;

}
