#include <iostream>
using namespace std;

#include <sys/time.h>
#include "sorters.h"
#include "sub.h"

//My test heap sorter.

void heaper(int n[], const int slot, const int max);
void heapsort(int max, int order){

  //Declaring variables...
  
  int i;
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
  
  //entire sorting algorithm right here.

  for(i=(max/2)-1;i>=0;i--)
    heaper(n, i, max);

  for(i=max-1;i>=1;i--){
    swap(&n[0], &n[i]);
    heaper(n, 0, i-1);
  }
  
  //that's it, folks.
  
  end = clock();
  
  //calculating time
  
  seconds = (end-start)/1000000;
  
  cout << "Sorting took " << seconds << " seconds to complete." << endl;
  
}

//this supposedly initializes the heap and reheaps it when sorting.

void heaper(int n[], int slot, int max){
  int x;
  bool complete = false;
  
  while((slot*2 <= max) && (!complete)){
    if(slot*2==max)
      x = slot*2;
    else if(n[slot*2]>n[slot*2 +1])
      x = slot*2;
    else
      x = slot*2+1;
    if (n[slot] < n[x]){
      swap(&n[slot], &n[x]);
      slot=x;
    }
    else
      complete = true;
  }
  
}