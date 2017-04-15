#include <iostream>
#include <string>
#include "sub.h"
#include <sys/types.h>
#include <unistd.h>
#include <omp.h>
using namespace std;


//Making static seed.
static int seed = 147;
int count = 0;
int total = 0;

//...to make the swap.

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//...to generate the random numbers.

int rng() {
    seed = (25173 * seed + 13849) % 65536;
    return seed;
}

//...to change seed.

void process() {
    seed = getpid();
}

//print integers

void pint(int x) {
    cout << x << endl;
}

//compare integers

int compint(int x, int y) {
    if (x > y)
        return 1;
    else if (x == y)
        return 0;
    else
        return -1;
}

/* Displaying what the current sorting alg, rank, and thread count is*/
void printPosition(string sort, int max) {
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();
    cout << "\n\n" <<"Currently at " << sort << ", sorting array size " << max << " of thread " << my_rank +1 << " of " << thread_count << endl;
}

/* Calculate Average*/
void average(float seconds) {
    if (count < 2) {
        total = total + seconds;
        count++;
    } else {
        float average = total/2;
        cout << "\n" << "The average of this sorting algorithm is " << average << endl;
        total = 0;
    }
}
