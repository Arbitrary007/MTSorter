#include <iostream>
#include "sorters.h"
#include <omp.h> 
#include "sub.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

/* MTSorter Program 
 *  By Team Divide by Zero (aka Team 1)
 *  Team members: Daniel Beck and Diane Truong
 *  Purpose: A program that utilizes multiple sorting algorithms and prints the running time average to a text file.
 */

/* So PrintToFile can read*/
float avgbubbleS = 0, avgbubbleM = 0, avgbubbleL = 0;
float avgcountS = 0, avgcountM = 0, avgcountL = 0;
float avgheapS = 0, avgheapM = 0, avgheapL = 0;
float avginsertS = 0, avginsertM = 0, avginsertL = 0;
float avgmergeS = 0, avgmergeM = 0, avgmergeL = 0;
float avgquickS = 0, avgquickM = 0, avgquickL = 0;
float avgradixS = 0, avgradixM = 0, avgradixL = 0;
float avgselectS = 0, avgselectM = 0, avgselectL = 0;

/* Print averages to file*/
void printToFile(ofstream& toFile, int Tcount, int S, int M, int L);

//setting up a menu to handle all tests at once.

int main(int argc, char *argv[]) {
    char end = 'n';
    int arrangement = 0, threads = 1, i = 0, display = 0;
    bool quit = false;

    //introduction to the program
    cout << endl << "Welcome to the Oklahoma City University MTSorter program." << endl;

    while (!quit) {
        if (argc == 1) {
            while (threads % 4 != 0) {
                /* Program accepts an argument for how many threads should be running */
                cout << "How many threads would you like to use? (It must be a multiple of four):" << endl;
                cin >> threads;

                if (threads % 4 != 0) {
                    cout << "Error! Please make your thread count a multiple of 4!" << endl;
                }
            }
        } else if (argc == 2) {//if thread count given via command line argument 
            threads = atoi(argv[1]);

            while (threads % 4 != 0) {
                cout << "Error! The given thread count is not a multiple of 4! Please enter one that is now:" << endl;
                cin >> threads;
            }
        } else {
            cout << "Error! Too many arguments given!" << endl;
            exit(-1);
        }

        //for sorting various other types of arrangements of numbers
        while ((arrangement < 1) || (arrangement > 4)) {
            cout << endl << "How would you like the numbers to be generated?" << endl << endl
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
            } else if (cin.fail()) {
                cout << "Sorry, you have entered an invalid value, please choose an option presented." << endl;
            }//else
        }//elihw

        /* Asks if user want the unsorted/sorted arrays displayed*/
        cout << "Would you like the values of the unsorted arrays and sorted arrays to be displayed? (y/n)";
	cin >> end;
	if (end == 'y' || end == 'Y'){
            cout << endl << "Warning: If you choose yes and had specified the program to run with more than one thread, the output will appear erratic. Are you sure? (y/n)" << endl;
       	    cin >> end;
	}

        /* Process input + Error check */
        if ((end == 'y') || (end == 'Y')) {
            display = 1;
        } else if ((end == 'n') || (end == 'N')) {
            display = 0;
        } else {
            cout << "Sorry, you have entered an invalid input, please try again" << endl;
        }
        cout << endl;

        cout << "Please wait while the arrays are being sorted." << endl << "It can be very fast or take a very long time." << endl;
        //building sorting sizes
        int sizeS = 100;
        int sizeM = 200;
        int sizeL = 400;

        //building result arrays (for finding averages of times)
        float bubbleS[threads], bubbleM[threads], bubbleL[threads];
        float countS[threads], countM[threads], countL[threads];
        float heapS[threads], heapM[threads], heapL[threads];
        float insertS[threads], insertM[threads], insertL[threads];
        float mergeS[threads], mergeM[threads], mergeL[threads];
        float quickS[threads], quickM[threads], quickL[threads];
        float radixS[threads], radixM[threads], radixL[threads];
        float selectS[threads], selectM[threads], selectL[threads];


#pragma omp parallel num_threads(threads)
        {
            //bubble sort segment
            bubbleS[omp_get_thread_num()] = bubble(sizeS, arrangement, display);
            bubbleM[omp_get_thread_num()] = bubble(sizeM, arrangement, display);
            bubbleL[omp_get_thread_num()] = bubble(sizeL, arrangement, display);
            //counting sort segment
            countS[omp_get_thread_num()] = counting(sizeS, arrangement, display);
            countM[omp_get_thread_num()] = counting(sizeM, arrangement, display);
            countL[omp_get_thread_num()] = counting(sizeL, arrangement, display);
            //heap sort segment
            heapS[omp_get_thread_num()] = heapsort(sizeS, arrangement, display);
            heapM[omp_get_thread_num()] = heapsort(sizeM, arrangement, display);
            heapL[omp_get_thread_num()] = heapsort(sizeL, arrangement, display);
            //insertion sort segment
            insertS[omp_get_thread_num()] = insertion(sizeS, arrangement, display);
            insertM[omp_get_thread_num()] = insertion(sizeM, arrangement, display);
            insertL[omp_get_thread_num()] = insertion(sizeL, arrangement, display);
            //merge sort segment
            mergeS[omp_get_thread_num()] = mergesort(sizeS, arrangement, display);
            mergeM[omp_get_thread_num()] = mergesort(sizeM, arrangement, display);
            mergeL[omp_get_thread_num()] = mergesort(sizeL, arrangement, display);
            //quicksort segment
            quickS[omp_get_thread_num()] = quicksort(sizeS, arrangement, display);
            quickM[omp_get_thread_num()] = quicksort(sizeM, arrangement, display);
            quickL[omp_get_thread_num()] = quicksort(sizeL, arrangement, display);
            //radix sort segment
            radixS[omp_get_thread_num()] = radixsort(sizeS, arrangement, display);
            radixM[omp_get_thread_num()] = radixsort(sizeM, arrangement, display);
            radixL[omp_get_thread_num()] = radixsort(sizeL, arrangement, display);
            //selection sort segment
            selectS[omp_get_thread_num()] = selection(sizeS, arrangement, display);
            selectM[omp_get_thread_num()] = selection(sizeM, arrangement, display);
            selectL[omp_get_thread_num()] = selection(sizeL, arrangement, display);
        }

        //test print of values... checking only one, though
        //for (i = 0; i < threads; i++) {
        //    cout << countL[i] << " ";
        //}
        //cout << endl;

        //average all the totals, starting with bubblesort
        for (i = 0; i < threads; i++) {
            avgbubbleS = avgbubbleS + bubbleS[i];
        }
        avgbubbleS = avgbubbleS / threads;
        for (i = 0; i < threads; i++) {
            avgbubbleM = avgbubbleM + bubbleM[i];
        }
        avgbubbleM = avgbubbleM / threads;
        for (i = 0; i < threads; i++) {
            avgbubbleL = avgbubbleL + bubbleL[i];
        }
        avgbubbleL = avgbubbleL / threads;
        //for counting sort averages
        for (i = 0; i < threads; i++) {
            avgcountS = avgcountS + countS[i];
        }
        avgcountS = avgcountS / threads;
        for (i = 0; i < threads; i++) {
            avgcountM = avgcountM + countM[i];
        }
        avgcountM = avgcountM / threads;
        for (i = 0; i < threads; i++) {
            avgcountL = avgcountL + countL[i];
        }
        avgcountL = avgcountL / threads;
        //heap sort averages
        for (i = 0; i < threads; i++) {
            avgheapS = avgheapS + heapS[i];
        }
        avgheapS = avgheapS / threads;
        for (i = 0; i < threads; i++) {
            avgheapM = avgheapM + heapM[i];
        }
        avgheapM = avgheapM / threads;
        for (i = 0; i < threads; i++) {
            avgheapL = avgheapL + heapL[i];
        }
        avgheapL = avgheapL / threads;
        //insertion sort averages
        for (i = 0; i < threads; i++) {
            avginsertS = avginsertS + insertS[i];
        }
        avginsertS = avginsertS / threads;
        for (i = 0; i < threads; i++) {
            avginsertM = avginsertM + insertM[i];
        }
        avginsertM = avginsertM / threads;
        for (i = 0; i < threads; i++) {
            avginsertL = avginsertL + insertL[i];
        }
        avginsertL = avginsertL / threads;
        //merge sort averages
        for (i = 0; i < threads; i++) {
            avgmergeS = avgmergeS + mergeS[i];
        }
        avgmergeS = avgmergeS / threads;
        for (i = 0; i < threads; i++) {
            avgmergeM = avgmergeM + mergeM[i];
        }
        avgmergeM = avgmergeM / threads;
        for (i = 0; i < threads; i++) {
            avgmergeL = avgmergeL + mergeL[i];
        }
        avgmergeL = avgmergeL / threads;
        //quick sort averages
        for (i = 0; i < threads; i++) {
            avgquickS = avgquickS + quickS[i];
        }
        avgquickS = avgquickS / threads;
        for (i = 0; i < threads; i++) {
            avgquickM = avgquickM + quickM[i];
        }
        avgquickM = avgquickM / threads;
        for (i = 0; i < threads; i++) {
            avgquickL = avgquickL + quickL[i];
        }
        avgquickL = avgquickL / threads;
        //radix sort averages
        for (i = 0; i < threads; i++) {
            avgradixS = avgradixS + radixS[i];
        }
        avgradixS = avgradixS / threads;
        for (i = 0; i < threads; i++) {
            avgradixM = avgradixM + radixM[i];
        }
        avgradixM = avgradixM / threads;
        for (i = 0; i < threads; i++) {
            avgradixL = avgradixL + radixL[i];
        }
        avgradixL = avgradixL / threads;
        //selection sort averages
        for (i = 0; i < threads; i++) {
            avgselectS = avgselectS + selectS[i];
        }
        avgselectS = avgselectS / threads;
        for (i = 0; i < threads; i++) {
            avgselectM = avgselectM + selectM[i];
        }
        avgselectM = avgselectM / threads;
        for (i = 0; i < threads; i++) {
            avgselectL = avgselectL + selectL[i];
        }
        avgselectL = avgselectL / threads;


        /*Print averages to file*/
        ofstream toFile;
        toFile.open("Output.txt");
        printToFile(toFile, threads, sizeS, sizeM, sizeL);
        toFile.close();
        cout << "The average time of all sorting algorithms runtimes are now printed out to Output.txt" << endl;

        // Ask if user wants to quit the program or run again
        cout << "Would you like to quit now (y/n)? ";
        cin >> end;
        if ((end == 'y') || (end == 'Y')) {
            quit = true;
        } else if ((end == 'n') || (end == 'N')) {
            arrangement = 0;
        } else {
            cout << "Sorry, you have entered an invalid input, please try again" << endl;
        }
        cout << endl;
    } //end of while
    return 0;
} //end of main

/*Print to file*/
void printToFile(ofstream& toFile, int Tcount, int S, int M, int L) {
    const int numWidth = 16;
    const char sep = ' ';
	//function that prints results to file toFile
    toFile << "SORTING ALGORITHM BENCHMARKS" << endl;;
    toFile << "Number of threads: " << Tcount << endl;
    toFile << "Sizes: Small: " << S << " Medium: " << M << " Large: " << L << endl << endl;
	//setting up table; sixteen characters for name; ten for each slot
    toFile << "                |     Small      |     Medium     |     Large      |" << endl;
    toFile << "-------------------------------------------------------------------|" << endl;
    toFile << "Bubble          |";
    toFile << right << setw(numWidth) << setfill(sep) << avgbubbleS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgbubbleM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgbubbleL << "|";
    toFile << endl;
    toFile << "Counting        |";
    toFile << right << setw(numWidth) << setfill(sep) << avgcountS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgcountM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgcountL << "|";
    toFile << endl;
    toFile << "Heap            |";
    toFile << right << setw(numWidth) << setfill(sep) << avgheapS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgheapM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgheapL << "|";
    toFile << endl;
    toFile << "Insertion       |";
    toFile << right << setw(numWidth) << setfill(sep) << avginsertS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avginsertM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avginsertL << "|";
    toFile << endl;
    toFile << "Merge           |";
    toFile << right << setw(numWidth) << setfill(sep) << avgmergeS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgmergeM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgmergeL << "|";
    toFile << endl;
    toFile << "Quick           |";
    toFile << right << setw(numWidth) << setfill(sep) << avgquickS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgquickM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgquickL << "|";
    toFile << endl;
    toFile << "Radix           |";
    toFile << right << setw(numWidth) << setfill(sep) << avgradixS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgradixM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgradixL << "|";
    toFile << endl;
    toFile << "Selection       |";
    toFile << right << setw(numWidth) << setfill(sep) << avgselectS << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgselectM << "|";
    toFile << right << setw(numWidth) << setfill(sep) << avgselectL << "|";
    toFile << endl;
    toFile << "--------------------------------------------------------------------" << endl;
}
