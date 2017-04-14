#include <iostream>
#include "sorters.h"
#include <omp.h> 
#include "sub.h"
#include <fstream>
#include <cstdlib>
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
void printToFile(ofstream& toFile);

//setting up a menu to handle all tests at once.

int main(int argc, char *argv[]) {
  char end = 'n';
  int arrangement=0, threads=1, i=0;
  bool quit = false;
  
  //introduction to the program
  cout << "Welcome to the Oklahoma City University MTSorter program." << endl;
  
  while (!quit) {
    if(argc==1){
      while(threads%4!=0){
	/* Program accepts an argument for how many threads should be running */
	cout << "How many threads would you like to use? (It must be a multiple of four):" << endl;
	cin >> threads;
	if(threads%4!=0){
	  cout << "Error! Please make your thread count a multiple of 4!" << endl;
	}
      }
    }else if(argc==2){//if thread count given via command line argument 
      threads=atoi(argv[1]);
      while (threads%4!=0){
	cout << "Error! The given thread count is not a multiple of 4! Please enter one that is now:" << endl;
	cin >> threads;
      }
    }else{
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
      }//fi
    }//elihw
    
    
    cout << "Please wait while the arrays are being sorted." << endl << "It can be very fast or take a very long time." << endl;
    //building sorting sizes
    int sizeS = 10;
    int sizeM = 50;
    int sizeL = 100;
    
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
      bubbleS[omp_get_thread_num()] = bubble(sizeS, arrangement);
      bubbleM[omp_get_thread_num()] = bubble(sizeM, arrangement);
      bubbleL[omp_get_thread_num()] = bubble(sizeL, arrangement);
      //counting sort segment
      countS[omp_get_thread_num()] = counting(sizeS, arrangement);
      countM[omp_get_thread_num()] = counting(sizeM, arrangement);
      countL[omp_get_thread_num()] = counting(sizeL, arrangement);
      //heap sort segment
      heapS[omp_get_thread_num()] = heapsort(sizeS, arrangement);
      heapM[omp_get_thread_num()] = heapsort(sizeM, arrangement);
      heapL[omp_get_thread_num()] = heapsort(sizeL, arrangement);
      //insertion sort segment
      insertS[omp_get_thread_num()] = insertion(sizeS, arrangement);
      insertM[omp_get_thread_num()] = insertion(sizeM, arrangement);
      insertL[omp_get_thread_num()] = insertion(sizeL, arrangement);
      //merge sort segment
      mergeS[omp_get_thread_num()] = mergesort(sizeS, arrangement);
      mergeM[omp_get_thread_num()] = mergesort(sizeM, arrangement);
      mergeL[omp_get_thread_num()] = mergesort(sizeL, arrangement);
      //quicksort segment
      quickS[omp_get_thread_num()] = quicksort(sizeS, arrangement);
      quickM[omp_get_thread_num()] = quicksort(sizeM, arrangement);
      quickL[omp_get_thread_num()] = quicksort(sizeL, arrangement);
      //radix sort segment
      radixS[omp_get_thread_num()] = radixsort(sizeS, arrangement);
      radixM[omp_get_thread_num()] = radixsort(sizeM, arrangement);
      radixL[omp_get_thread_num()] = radixsort(sizeL, arrangement);
      //selection sort segment
      selectS[omp_get_thread_num()] = selection(sizeS, arrangement);
      selectM[omp_get_thread_num()] = selection(sizeM, arrangement);
      selectL[omp_get_thread_num()] = selection(sizeL, arrangement);
    }
    
    //test print of values... checking only one, though
    for (i = 0; i < threads; i++) {
      cout << countL[i] << " ";
    }
    cout << endl;
    
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
    
    
    /*Open file to print*/
    ofstream toFile;
    toFile.open("Output.txt");
    /*Print Averages */
    printToFile(toFile);
    /*close output file*/
    toFile.close();
    cout << "The average time of all sorting algorithms runtimes are now printed out to Output.txt" << endl;
    
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
  return 0;
} //end of main

  /*Print to file*/
void printToFile(ofstream& toFile) {
  toFile << "The average of Bubble sort, sorting array size S, is " << avgbubbleS << "\n";
  toFile << "The average of Bubble sort, sorting array size M, is " << avgbubbleM << "\n";
  toFile << "The average of Bubble sort, sorting array size L, is " << avgbubbleL << "\n";
  toFile << "The average of Count sort, sorting array size S, is " << avgcountS << "\n";
  toFile << "The average of Count sort, sorting array size M, is " << avgcountM << "\n";
  toFile << "The average of Count sort, sorting array size L, is " << avgcountL << "\n";
  toFile << "The average of Heap sort, sorting array size S, is " << avgheapS << "\n";
  toFile << "The average of Heap sort, sorting array size M, is " << avgheapM << "\n";
  toFile << "The average of Heap sort, sorting array size L, is " << avgheapL << "\n";
  toFile << "The average of Insertion sort, sorting array size S, is " << avginsertS << "\n";
  toFile << "The average of Insertion sort, sorting array size M, is " << avginsertM << "\n";
  toFile << "The average of Insertion sort, sorting array size L, is " << avginsertL << "\n";
  toFile << "The average of Merge sort, sorting array size S, is " << avgmergeS << "\n";
  toFile << "The average of Merge sort, sorting array size M, is " << avgmergeM << "\n";
  toFile << "The average of Merge sort, sorting array size L, is " << avgmergeL << "\n";
  toFile << "The average of Quick sort, sorting array size S, is " << avgquickS << "\n";
  toFile << "The average of Quick sort, sorting array size M, is " << avgquickM << "\n";
  toFile << "The average of Quick sort, sorting array size L, is " << avgquickL << "\n";
  toFile << "The average of Radix sort, sorting array size S, is " << avgradixS << "\n";
  toFile << "The average of Radix sort, sorting array size M, is " << avgradixM << "\n";
  toFile << "The average of Radix sort, sorting array size L, is " << avgradixL << "\n";
  toFile << "The average of Selection sort, sorting array size S, is " << avgselectS << "\n";
  toFile << "The average of Selection sort, sorting array size M, is " << avgselectM << "\n";
  toFile << "The average of Selection sort, sorting array size L, is " << avgselectL << "\n";
}
