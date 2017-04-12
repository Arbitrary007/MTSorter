#include <iostream>
#include "sorters.h"
#include <omp.h> 
#include "sub.h"
using namespace std;

//setting up a menu to handle all tests at once.
main() {
    char end = 'n';
    int numbers = 0, arrangement = 0, threads = 0;
    bool quit = false;

	//introduction to the program
    cout << "Welcome to the Oklahoma City University MTSorter program." << endl;
	
    while (!quit) {
        /* Program accepts an argument for how many threads should be running */
        cout << "How many threads would you like to use? (It is preferred if the number of threads is an even number)" << endl;
        cin >> threads;
	//for sorting various other types of arrangements of numbers
        while ((arrangement < 1) || (arrangement > 4)) {
            cout << "How would you like the numbers to be generated?" << endl << endl
                    << "1 --> increasing (1,2,3,4,...)" << endl
                    << "2 --> decreasing (...,4,3,2,1)" << endl
                    << "3 --> random (3,1,4,2,...)" << endl /*Note to self: Always pick 3*/
                    << "4 --> all one number (1,1,1,1,...)" << endl
                    << "Enter selection:" << endl;
            cin >> arrangement;
            cout << endl;
            //error checking
            if ((arrangement < 1) || (arrangement > 4)) {
                arrangement = 0;
	     	cout << "I'm sorry, but you must choose an option presented. Please try again." << endl;
            }
        }

	//building sorting sizes
        int sizeS = 10;
        int sizeM = 50;
	int sizeL = 100;

	//building result arrays (for finding averages of times) and average totals
	float bubbleS[threads], bubbleM[threads], bubbleL[threads];
	float avgbubbleS=0, avgbubbleM=0, avgbubbleL=0;
	float countS[threads], countM[threads], countL[threads];
	float avgcountS=0, avgcountM=0, avgcountL=0;
	float heapS[threads], heapM[threads], heapL[threads];
	float avgheapS=0, avgheapM=0, avgheapL=0;
	float insertS[threads], insertM[threads], insertL[threads];
	float avginsertS=0, avginsertM=0, avginsertL=0;
	float mergeS[threads], mergeM[threads], mergeL[threads];
	float avgmergeS=0, avgmergeM=0, avgmergeL=0;
	float quickS[threads], quickM[threads], quickL[threads];
	float avgquickS=0, avgquickM=0, avgquickL=0;
	float radixS[threads], radixM[threads], radixL[threads];
	float avgradixS=0, avgradixM=0, avgradixL=0;
	float selectS[threads], selectM[threads], selectL[threads];
	float avgselectS=0, avgselectM=0, avgselectL=0;

#pragma omp parallel num_threads(threads)  
        {
		//bubble sort segment
            bubble(sizeS, arrangement);
            bubble(sizeM, arrangement);
	    bubble(sizeL, arrangement);
		//counting sort segment
            counting(sizeS, arrangement);
            counting(sizeM, arrangement);
	    counting(sizeL, arrangement);
		//heap sort segment
            heapsort(sizeS, arrangement);
            heapsort(sizeM, arrangement);
	    heapsort(sizeL, arrangement);
		//insertion sort segment
            insertion(sizeS, arrangement);
            insertion(sizeM, arrangement);
	    insertion(sizeL, arrangement);
		//merge sort segment
            mergesort(sizeS, arrangement);
            mergesort(sizeM, arrangement);
	    mergesort(sizeL, arrangement);
		//quicksort segment
            quicksort(sizeS, arrangement);
            quicksort(sizeM, arrangement);
	    quicksort(sizeL, arrangement);
		//radix sort segment
            radixsort(sizeS, arrangement);
            radixsort(sizeM, arrangement);
	    radixsort(sizeL, arrangement);
		//selection sort segment
            selection(sizeS, arrangement);
            selection(sizeM, arrangement);
	    selection(sizeL, arrangement);
        }

        // Ask if user wants to quit the program or run again
        cout << "Would you like to quit now (y/n)? ";
        cin >> end;
        if ((end == 'y') || (end == 'Y')) {
            quit = true;
        } else {
            arrangement = 0;
        }
        cout << endl;
    } //end of while
} //end of main
