all: mergeSort

clean:
	rm mergeSort.o mergeSort

mergeSort: mergeSort.o
	g++ -g -o mergeSort mergeSort.o

mergeSort.o: mergeSort.cpp
	g++ -c -g mergeSort.cpp