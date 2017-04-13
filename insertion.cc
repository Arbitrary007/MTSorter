#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include "pq.h"
#include <omp.h>
using namespace std;



//My test insertion sorter.

float insertion(int max, int order) {

    //Declaring variables...

    int i;
    int n[max];
    PRIQUEUE IPQ;
    float start, end, seconds;

    //initializing IPQ...

    Init(&IPQ);

    //getting numbers for sorting...

    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    printPosition("insertion sort", max);

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

    /* Printing unsorted Insertion Array */
    cout << "Printing unsorted Insertion Array ... " << endl;
    for (int i = 0; i < max; i++) cout << n[i] << " ";
    cout << endl;

    //sorting (timed)

    start = clock();

    for (i = 0; i < max; i++) {
        Push(&IPQ, n[i]);
    }

    for (i = 0; i < max; i++) {
        n[i] = Pop(&IPQ);
    }

    end = clock();

    //calculating time

    seconds = (end - start) / 1000000;

    cout << "Sorting took " << seconds << " seconds to complete." << endl;

    /* Printing sorted Insertion Array*/
    cout << "Printing sorted Insertion Array ... " << endl;
    for (int i = 0; i < max; i++) cout << n[i] << " ";
    cout << endl;

    //return findings to main
    return seconds;

}
