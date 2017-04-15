#include <iostream>
#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include <omp.h>
using namespace std;

/* Counting sort */
float counting(int max, int order, int display) {
    
    /* Variables... */
    int i;
    float start, end, seconds;
    int n[max];
    int size = sizeof (n) / sizeof (int);

    //getting numbers for sorting...
    process();

    /*Displaying what the current sorting alg, rank, and thread count is*/
    if (display == 1) {
        printPosition("Counting sort", max);
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

    /* Printing unsorted Counting Array */
    if (display == 1) {
        cout << "Printing unsorted Counting Array ... " << endl;
        for (int i = 0; i < max; i++) cout << n[i] << " ";
        cout << endl;
    }

    /* Counting Sort*/
    if (order == 2) { /* Counting sorts descending order a little differently from the rest*/;
        int count[max], output[max];
        int k = max + 1;
        int l = 0;

        //sorting (timed)
        start = clock();
        
        /* Begin sorting*/
        for (int i = 0; i < k; i++) count[i] = 0;
        for (int i = 0; i < max; i++) count[n[i]]++;
        for (int i = k - 1; i > 0; i--) count[i - 1] += count[i];
        for (int j = 0; j < max; j++) count[n[j]]--;
        for (int i = max - 1; i >= 0; i--) {
            output[l] = count[i];
            l++;
        }

        end = clock();
        //calculating time
        seconds = (end - start) / 1000000;

        if (display == 1) {
            cout << "Sorting took " << seconds << " seconds to complete." << endl; //printing sorting time
            cout << "Printing sorted Counting Array ... " << endl; /* Printing sorted Counting Array*/
            for (int i = 0; i < max; i++) cout << output[i] << " ";
            cout << endl;
        }

    } else if (order != 2 ){
        int k = n[0];

        //sorting (timed)
        start = clock();
        
        /*Begin sorting*/
        for (int i = 1; i < size; i++) {
            if (n[i] > k) k = n[i];
        }
        int *output = new int[size];
        for (int i = 0; i < size; i++) output[i] = 0;
        int *count = new int[k + 1];
        for (int i = 0; i < k + 1; i++) count[i] = 0;
        for (int i = 0; i < size; i++) count[n[i]]++;
        for (int i = 1; i < k + 1; i++) count[i] += count[i - 1];
        for (int i = size - 1; i >= 0; i--) {
            output[count[n[i]] - 1] = n[i];
            count[n[i]]--;
        }

        end = clock();
        //calculating time
        seconds = (end - start) / 1000000;

        if (display == 1) {
            cout << "Sorting took " << seconds << " seconds to complete." << endl; //printing sorting time
            cout << "Printing sorted Counting Array ... " << endl; /* Printing sorted Counting Array*/
            for (int i = 0; i < max; i++) cout << output[i] << " ";
            cout << endl;
        }
    }

    //return findings to main
    return seconds;

}
