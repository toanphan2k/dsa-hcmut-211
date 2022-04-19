#ifndef SORTING_H
#define SORTING_H
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;
template <class T>
class Sorting {
private:
    static T* Partition(T* start, T* end) ;
public:
    static void QuickSort(T* start, T* end) ;
};
template <class T>
static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T pivot = start[0];    // pivot
	int i = 0;
	int j = end - start;
    do {
        do {
            i++;
        } 
        while (start[i] <= pivot);
        do {
            j--;
        } 
        while (start[j]>pivot);
        
        swap(start[i], start[j]);
    } 
    while (i<j);

	swap(start[i], start[j]);
	swap(start[0], start[j]);
	return start + j;
}

template <class T>
static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if (start >= end) return;
    T* index = Partition(start, end);    
    cout << index - start << " ";
    QuickSort(start, index);
    QuickSort(index + 1, end);
}
#endif /* SORTING_H */