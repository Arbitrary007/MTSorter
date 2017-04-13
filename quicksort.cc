#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;



//My quicksorter.


void qsort(int n[], int l, int r);

float quicksort(int max, int order) {

    //Declaring variables...

    int i;
    int l, r;
    int n[max];
    float start, end, seconds;

    l = 0;

    r = max - 1;

    //getting numbers for sorting...

    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    //printPosition("Quick sort", max);

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

    /* Printing unsorted Quicksort Array */ //troubleshooting
    //cout << "Printing unsorted Quicksort Array ... " << endl;
    //for (int i = 0; i < max; i++) cout << n[i] << " ";
    //cout << endl;


    //sorting (timed)

    start = clock();

    qsort(n, l, r);

    end = clock();

    //calculating time

    seconds = (end - start) / 1000000;

    //cout << "Sorting took " << seconds << " seconds to complete." << endl;

    /* Printing sorted Quicksort Array*/
    //cout << "Printing sorted QuickSort Array ... " << endl;
    //for (int i = 0; i < max; i++) cout << n[i] << " ";
    //cout << endl;

    //send findings to main
    return seconds;

}

void qsort(int n[], int l, int r) {

    int i, last;

    if (l >= r) {
        return;
    }
    swap(&(n[l]), &(n[(l + r) / 2]));
    last = l;
    for (i = l + 1; i <= r; i++) {
        if (n[i] < n[l]) {
            swap(&(n[++last]), &(n[i]));
        }
    }
    swap(&(n[l]), &(n[last]));
    qsort(n, l, last - 1);
    qsort(n, last + 1, r);
}
