#include <iostream>
using namespace std;

#include "sub.h"
#include <sys/time.h>
#include "sorters.h"

//My test  quicksorter.


void qsort(int n[], int l, int r);
void quicksort(int max, int order){

  //Declaring variables...
  
  int i;
  int l, r;
  int n[max];
  float start, end, seconds;

  l = 0;

  r = max-1;

  //getting numbers for sorting...

  process();

  for(i=0;i<max;i++){

    if (order == 3){
      n[i]=rng();
    }else if(order == 2){
      n[i]=max-i;
    }else if(order == 1){
      n[i]=i;
    }else if(order == 4){
      n[i]=1;
    }

  }

  //sorting (timed)

  start = clock();

  qsort(n, l, r);

  end = clock();

  //calculating time

  seconds = (end-start)/1000000;

  cout << "Sorting took " << seconds << " seconds to complete." << endl;

}

void qsort(int n[], int l, int r){

  int i, last;

  if(l >= r){
    return;
  }
  swap(&(n[l]), &(n[(l+r)/2]));
  last = l;
  for(i = l + 1; i <= r; i++){
    if (n[i] < n[l]){
      swap (&(n[++last]), &(n[i]));
    }
  }
  swap(&(n[l]), &(n[last]));
  qsort(n, l, last-1);
  qsort(n, last+1, r);
}
