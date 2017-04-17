#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;



//My test selection sorter.

float selection(int max, int order, int display) {

    //Declaring variables...

    int startsort, small, i;
    int n[max];
    float start, end, seconds;

    //getting numbers for sorting...

    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    if (display == 1) {
        printPosition("selection sort", max);
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

    /* Printing unsorted Selection Array */
    if (display == 1) {
        cout << "Printing unsorted Selection Array ... " << endl;
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //sorting (timed)

    start = clock();

    for (startsort = 0; startsort < max - 1; startsort++) {
        small = startsort;
        for (i = startsort; i < max; i++) {
            if (n[i] < n[small]) {
                small = i;
            }
        }
        swap(&(n[small]), &(n[startsort]));
    }

    end = clock();

    //calculating time

    seconds = (end - start) / 1000000;

    if (display == 1) {
        cout << "Sorting took " << seconds << " seconds to complete." << endl; //printing sorting time
        cout << "Printing Selection Array ... " << endl; /* Printing sorted Selection Array*/
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    //send back the findings to main
    return seconds;

}
