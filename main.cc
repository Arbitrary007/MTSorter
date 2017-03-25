#include <iostream>
using namespace std;

#include "sorters.h"

//setting up a menu to handle all tests at once.

main(){

  char sorter = 'z';
  char  end = 'n';
  int numbers = 0, arrangement = 0;
  bool quit = false;

  cout << "Welcome to Daniel's sorter program." << endl;
  
  while (!quit){

    while((((sorter < 'A') || (sorter > 'I')) && (sorter != 'Q'))
	  &&(((sorter < 'a') || (sorter > 'i')) && (sorter != 'q'))){

      cout << "Which sorter would you like to use?" << endl << endl
	   << "A --> bubble sort" << endl
	   << "B --> selection sort" << endl
	   << "C --> instertion sort" << endl
	   << "D --> quicksort" << endl
	   << "E --> heap sorter" << endl
	   << "Q --> Quit" << endl
	   << "Enter selection:" << endl;
      
      cin >> sorter;
      cout << endl;
      
      if((((sorter < 'A') || (sorter > 'E')) && (sorter != 'Q'))
	  &&(((sorter < 'a') || (sorter > 'e')) && (sorter != 'q'))){

	sorter = 'z';
      }

    }
    
    if ((sorter != 'Q') && (sorter != 'q')){
      
      while ((numbers < 2) || (numbers > 1000000000)){
	cout << "How many numbers would you like to sort (2-1000000000)?" << endl
	     << "Enter selection:" << endl;
	
	cin >> numbers;
	cout << endl;
	
	if ((numbers < 2) || (numbers > 1000000000)){
	  numbers = 0;
	}

      }
      
      while ((arrangement < 1) || (arrangement > 4)){
	cout << "How would you like the numbers?" << endl << endl
	     << "1 --> increasing (1,2,3,4,...)" << endl
	     << "2 --> decreasing (...,4,3,2,1)" << endl
	     << "3 --> random (3,1,4,2,...)" << endl
	     << "4 --> all one number (1,1,1,1,...)" << endl
	     << "Enter selection:" << endl;
	
	cin >> arrangement;
	cout << endl;

	if((arrangement < 1) || (arrangement > 4)){
	  arrangement = 0;
	}
	
      }
      
      switch(sorter){
        case 'A':
        case 'a':bubble(numbers, arrangement);
	  break;
        case 'B':
        case 'b':selection(numbers, arrangement);
	  break;
        case 'C':
        case 'c':insertion(numbers, arrangement);
	  break;
        case 'D':
        case 'd':quicksort(numbers, arrangement);
	  break;
        case 'E':
        case 'e':heapsort(numbers, arrangement);
	  break;
      }
      
      cout << "Would you like to quit now (y/n)? ";
      cin >> end;
      if ((end == 'y') || (end == 'Y')){
	quit = true;
      }else{
	numbers = 0;
	arrangement = 0;
	sorter = 'z';
      }
      
      cout << endl;

    }else{
      quit = true;
    }
  }
}
