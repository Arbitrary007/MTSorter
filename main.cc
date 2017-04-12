#include <iostream>
#include "sorters.h"
#include <omp.h> 
#include "sub.h"
#include <fstream>
using namespace std;

//setting up a menu to handle all tests at once.
main() {
    char end = 'n';
    int numbers = 0, arrangement = 0, threads, i=0;
    bool quit = false;

	//disable dynamic threads
	omp_set_dynamic(0);

	//introduction to the program
    cout << "Welcome to the Oklahoma City University MTSorter program." << endl;
	
    while (!quit) {
        /* Program accepts an argument for how many threads should be running */
        cout << "How many threads would you like to use? (It is preferred if the number of threads is an even number)" << endl;
        cin >> threads;
	cout << "You input " << threads << "." << endl;
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
        int sizeS = 100;
        int sizeM = 200;
	int sizeL = 400;

	/*Open file to print*/
	ofstream toFile;
	toFile.open("Output.txt");

	omp_set_num_threads(threads);

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
            bubbleS[omp_get_thread_num()]=bubble(sizeS, arrangement);
            bubbleM[omp_get_thread_num()]=bubble(sizeM, arrangement);
	    bubbleL[omp_get_thread_num()]=bubble(sizeL, arrangement);
		//counting sort segment
            countS[omp_get_thread_num()]=counting(sizeS, arrangement);
            countM[omp_get_thread_num()]=counting(sizeM, arrangement);
	    countL[omp_get_thread_num()]=counting(sizeL, arrangement);
		//heap sort segment
            heapS[omp_get_thread_num()]=heapsort(sizeS, arrangement);
            heapM[omp_get_thread_num()]=heapsort(sizeM, arrangement);
	    heapL[omp_get_thread_num()]=heapsort(sizeL, arrangement);
		//insertion sort segment
            insertS[omp_get_thread_num()]=insertion(sizeS, arrangement);
            insertM[omp_get_thread_num()]=insertion(sizeM, arrangement);
	    insertL[omp_get_thread_num()]=insertion(sizeL, arrangement);
		//merge sort segment
            mergeS[omp_get_thread_num()]=mergesort(sizeS, arrangement);
            mergeM[omp_get_thread_num()]=mergesort(sizeM, arrangement);
	    mergeL[omp_get_thread_num()]=mergesort(sizeL, arrangement);
		//quicksort segment
            quickS[omp_get_thread_num()]=quicksort(sizeS, arrangement);
            quickM[omp_get_thread_num()]=quicksort(sizeM, arrangement);
	    quickL[omp_get_thread_num()]=quicksort(sizeL, arrangement);
		//radix sort segment
            radixS[omp_get_thread_num()]=radixsort(sizeS, arrangement);
            radixM[omp_get_thread_num()]=radixsort(sizeM, arrangement);
	    radixL[omp_get_thread_num()]=radixsort(sizeL, arrangement);
		//selection sort segment
            selectS[omp_get_thread_num()]=selection(sizeS, arrangement);
            selectM[omp_get_thread_num()]=selection(sizeM, arrangement);
	    selectL[omp_get_thread_num()]=selection(sizeL, arrangement);
        }

	//test print of values... checking only one, though
	for (i=0;i<threads;i++){
	    cout<< countL[i] << " ";
	}
	cout << endl;

	//average all the totals

	/*close output file*/
	toFile.close();

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

/*Print to file*/
void printToFile(ofstream& toFile){
    toFile << " sorting " << " size array " << " took " << " seconds to complete.\n";
    toFile << "The average of this sorting algorithm is\n";
}
