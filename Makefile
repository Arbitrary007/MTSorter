CC= g++
CFLAGS= -g -Wall -fopenmp
LDFLAGS=
OBJS= main.o sub.o bubble.o counting.o heapsort.o insertion.o pq.o mergesort.o quicksort.o radix.o selection.o 
DEPS= main.cc sub.cc bubble.cc counting.cc heapsort.cc insertion.cc pq.cc mergesort.cc quicksort.cc radix.cc selection.cc
CO= -o
EXE=MTSorter

MTSorter: $(DEPS)
	$(CC) $(CFLAGS) $(CO) $(EXE) $(DEPS) $(LDFLAGS)

##-------------
#INCLUDE deps

deps:
	makedeps *.cc *.h

clean:
	rm MTSorter $(OBJS) *~ Output.txt
