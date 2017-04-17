#include "pq.h"
#include <omp.h>

// this will enter a value into the P.Q.

void Push (PRIQUEUE *Q, int x){
  PRIQUEUE t;
  if(*Q == NULL){
    t = new struct stacknode;
    t -> data = x;
    t -> next = NULL;
    *Q = t;
  }else{
    if(x < (*Q) -> data){
      t = new struct stacknode;
      t -> data = x;
      t -> next = *Q;
      *Q = t;
    }else{
      Push(&((*Q) -> next), x);
    }
  }
}

// this will retrieve value from the P.Q.

int Pop (PRIQUEUE *Q){
  int x;
  PRIQUEUE t;
  t = *Q;
  x = t -> data;
  *Q = t -> next;
  delete t;
  return x;
}

// this will initialize the P.Q.

void Init (PRIQUEUE *Q){
  *Q = NULL;
}

// this will ensure that the P.Q. is not empty

bool Empty (PRIQUEUE Q){
  return (Q == NULL);
}

// this will determine if the computer is capable of holding another value in the P.Q.

bool Full (PRIQUEUE Q){
  PRIQUEUE t;
  t = new struct stacknode;
  if (t != NULL){
    delete t;
    return false;
  }else{
    return true;
  }
}

// this will print the P.Q. (newest to oldest)

void ListPQ (PRIQUEUE Q){
  if (! Empty(Q)){
    cout << (Q -> data) << endl;;
    ListPQ(Q -> next);
  }
}

// this will print the P.Q. (oldest to newest)

void RevPQ (PRIQUEUE Q){
  if (! Empty(Q)){
    RevPQ(Q -> next);
    cout << (Q -> data) << endl;
  }
}
