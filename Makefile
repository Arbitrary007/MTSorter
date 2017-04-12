CC= g++
CFLAGS= -g -Wall -fopenmp
LDFLAGS=
SRC= main.cc sub.cc bubble.cc counting.cc heapsort.cc insertion.cc pq.cc mergesort.cc quicksort.cc radix.cc selection.cc 
OBJS= main.o sub.o bubble.o counting.o heapsort.o insertion.o pq.o mergesort.o quicksort.o radix.o selection.o 
CO= -o
EXE=MTSorter

MTSorter: $(SRC)
	$(CC) $(CFLAGS) $(CO) $(EXE) $(SRC) $(LDFLAGS)

##-------------
#INCLUDE deps

deps:
	makedeps *.cc *.h

clean:
	rm $(OBJS) *~
