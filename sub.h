#ifndef SUB_H
#define SUB_H
#include <string>
#include <omp.h>
using std::string;

//...to make the swap.
void swap(int *a, int *b);

//...to generate the random numbers.
int rng();

//...to set seed.
void process();

//integer printer
void pint(int x);

//integer comparer
int compint(int x, int y);

/* Display thread information*/
void printPosition(string sort, int max);

/* Write output to file*/
void printToFile(string filename);

/* Calculates averages of the sorting algorithms*/
void average(float seconds);

#endif
