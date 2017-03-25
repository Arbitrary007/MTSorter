#include <iostream>
using namespace std;

#include "sub.h"
#include <sys/time.h>
#include "sorters.h"

//My test bubble sorter.

void bubble(int max, int order){

  //Declaring variables...

  int i, j;
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

  for(j=0;j<max;j++){
    for(i=0;i<max-1;i++){
      if(n[i] > n[i+1]){
	swap(&(n[i]), &(n[i+1]));
      }
    }
  }

  end = clock();

  //calculating time

  seconds = (end-start)/1000000;

  cout << "Sorting took " << seconds << " seconds to complete." << endl;

}
