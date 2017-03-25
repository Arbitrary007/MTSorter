#include <iostream>
using namespace std;

#include "sub.h"
#include <sys/types.h>
#include <unistd.h>

//Making static seed.

static int seed = 147;

//...to make the swap.

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

//...to generate the random numbers.

int rng(){
  seed = (25173 * seed + 13849) % 65536;
  return seed;
}

//...to change seed.

void process(){
  seed = getpid();
}

//print integers

void pint(int x){

  cout << x << endl;

}

//compare integers

int compint(int x, int y){

  if (x > y)
    return 1;
  else if(x == y)
    return 0;
  else
    return -1;

}
