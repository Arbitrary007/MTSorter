#include <iostream>
#include "sorters.h"
#include <omp.h> 
#include "sub.h"
using namespace std;


//setting up a menu to handle all tests at once.

main() {
    char sorter = 'z';
    char end = 'n';
    int numbers = 0, arrangement = 0, threads = 0;
    bool quit = false;


    cout << "Welcome to the Oklahoma City University MTSorter program." << endl;

    while (!quit) {
        /* Program accepts an argument for how many threads should be running */
        cout << "How many threads would you like to use? (It is preferred if the number of threads is an even number)" << endl;
        cin >> threads;

        while ((arrangement < 1) || (arrangement > 4)) {
            cout << "How would you like the numbers to be generated?" << endl << endl
                    << "1 --> increasing (1,2,3,4,...)" << endl
                    << "2 --> decreasing (...,4,3,2,1)" << endl
                    << "3 --> random (3,1,4,2,...)" << endl /*Note to self: Always pick 3*/
                    << "4 --> all one number (1,1,1,1,...)" << endl
                    << "Enter selection:" << endl;
            cin >> arrangement;
            cout << endl;
            if ((arrangement < 1) || (arrangement > 4)) {
                arrangement = 0;
            }
        }
        
        int sizeA = 10;
        int sizeB = 50;

#pragma omp parallel num_threads(threads)  
        {
            bubble(sizeA, arrangement);
            bubble(sizeB, arrangement);
            counting(sizeA, arrangement);
            counting(sizeB, arrangement);
            heapsort(sizeA, arrangement);
            heapsort(sizeB, arrangement);
            insertion(sizeA, arrangement);
            insertion(sizeB, arrangement);
            mergesort(sizeA, arrangement);
            mergesort(sizeB, arrangement);
            quicksort(sizeA, arrangement);
            quicksort(sizeB, arrangement);
            radixsort(sizeA, arrangement);
            radixsort(sizeB, arrangement);
            selection(sizeA, arrangement);
            selection(sizeB, arrangement);
        }

        // Ask if user wants to quit the program or run again
        cout << "Would you like to quit now (y/n)? ";
        cin >> end;
        if ((end == 'y') || (end == 'Y')) {
            quit = true;
        } else {
            numbers = 0;
            arrangement = 0;
            sorter = 'z';
        }
        cout << endl;
    } //end of while
} //end of main