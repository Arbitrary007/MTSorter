#ifndef PQ_H
#define PQ_H

/*include standard libraries and boolean type*/

#include <iostream>
using namespace std; 

/*defining a priority queue*/

typedef struct stacknode{
  int data;
  struct stacknode *next;
} *PRIQUEUE;

/*declaring subprograms*/

/*this will enter a value into the P.Q.*/

void Push (PRIQUEUE *Q, int x);

/*this will retrieve value from the P.Q.*/

int Pop (PRIQUEUE *Q);

/*this will initialize the P.Q.*/

void Init (PRIQUEUE *Q);

/*this will ensure that the P.Q. is not empty*/

bool Empty (PRIQUEUE Q);

/*this will determine if the computer is capable of holding another value in the P.Q.*/

bool Full (PRIQUEUE Q);

/*this will print the P.Q. (newest to oldest)*/

void ListPQ (PRIQUEUE Q);

/*this will print the P.Q. (oldest to newest)*/

void RevPQ (PRIQUEUE Q);

#endif
