#include <iostream>
using namespace std;

#include "sub.h"
#include <sys/time.h>
#include "sorters.h"

//My test selection sorter.

void selection(int max, int order){

  //Declaring variables...

  int startsort, small, i;
  int n[max];
  float start, end, seconds;

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

  for(startsort=0;startsort<max-1;startsort++){
    small=startsort;
    for(i=startsort;i<max;i++){
      if(n[i] < n[small]){
	small = i;
      }
    }
    swap(&(n[small]), &(n[startsort]));
  }

  end = clock();

  //calculating time

  seconds = (end-start)/1000000;

  cout << "Sorting took " << seconds << " seconds to complete." << endl;

}
