#include "sorters.h"
#include <omp.h> 
#include "sub.h"
#include <iostream>
#include <fstream>
using namespace std;


//setting up a menu to handle all tests at once.

int main() {
    char sorter = 'z';
    char end = 'n';
    int numbers = 0, arrangement = 0, threads = 0;
    bool quit = false;

    cout << "Welcome to the Oklahoma City University MTSorter program." << endl;

    while (!quit) {
        /* Program accepts an argument for how many threads should be running */
        cout << "How many threads would you like to use? (It is preferred if the number of threads is an even number)" << endl;
        cin >> threads;
        
        cout << "Note: If the program suddenly stops at a sorting algorithm, please close and try running again.\n" << endl;
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

        /* Sizes: */
        int sizeA = 10;
        int sizeB = 50;
        int sizeC = 100;
        
        /* Open file to print*/
        ofstream toFile;
        toFile.open("Output.txt");
#pragma omp parallel num_threads(threads)  
        {
            bubble(sizeA, arrangement);
            bubble(sizeB, arrangement);
            bubble(sizeC, arrangement);
            counting(sizeA, arrangement);
            counting(sizeB, arrangement);
            counting(sizeC, arrangement);
            heapsort(sizeA, arrangement);
            heapsort(sizeB, arrangement);
            heapsort(sizeC, arrangement);
            insertion(sizeA, arrangement);
            insertion(sizeB, arrangement);
            insertion(sizeC, arrangement);
            mergesort(sizeA, arrangement);
            mergesort(sizeB, arrangement);
            mergesort(sizeC, arrangement);
            quicksort(sizeA, arrangement);
            quicksort(sizeB, arrangement);
            quicksort(sizeC, arrangement);
            radixsort(sizeA, arrangement);
            radixsort(sizeB, arrangement);
            radixsort(sizeC, arrangement);
            selection(sizeA, arrangement);
            selection(sizeB, arrangement);
            selection(sizeC, arrangement);
        }
        /* Close file after done sorting*/
        toFile.close();

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
    return 0;
} //end of main


/* Print to file*/
void printToFile(ofstream& toFile) {
    /* Some toFile are missing variables but should work once the arrays and variables are given*/
    toFile << " sorting " << " size array " << " took " << " seconds to complete.\n";
    toFile << "The average of this sorting algorithm is\n";
}