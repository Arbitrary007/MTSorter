CC= g++
CFLAGS=
LDFLAGS=
OBJS= main.o sub.o bubble.o selection.o pq.o insertion.o quicksort.o heapsort.o
CO=-o
EXE=MTSorter

MTSorter: $(OBJS)
	$(CC) $(CO) $(EXE) $(OBJS) $(LDFLAGS)

##-------------
#INCLUDE deps

deps:
	makedeps *.cc *.h

clean:
	rm MTSorter $(OBJS) *~
