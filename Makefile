CC= g++
CFLAGS= -g -Wall -fopenmp
LDFLAGS=
OBJS= main.o sub.o bubble.o counting.o heapsort.o insertion.o pq.o mergesort.o quicksort.o radix.o selection.o 
CO= -o
EXE=MTSorter

MTSorter: $(OBJS)
	$(CC) $(CFLAGS) $(CO) $(EXE) $(OBJS) $(LDFLAGS)

##-------------
#INCLUDE deps

deps:
	makedeps *.cc *.h

clean:
	rm MTSorter $(OBJS) *~
