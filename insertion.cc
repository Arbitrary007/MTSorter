#include <iostream>
using namespace std;

#include "sub.h"
#include <sys/time.h>
#include "sorters.h"
#include "pq.h"

//My test selection sorter.

void insertion(int max, int order){

  //Declaring variables...

  int i;
  int n[max];
  PRIQUEUE IPQ;
  float start, end, seconds;

  //initializing IPQ...

  Init(&IPQ);

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

  for(i=0;i<max;i++){
    Push(&IPQ, n[i]);
  }

  for(i=0;i<max;i++){
    n[i] = Pop(&IPQ);
  }

  end = clock();

  //calculating time

  seconds = (end-start)/1000000;

  cout << "Sorting took " << seconds << " seconds to complete." << endl;

}
