#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};

template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
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
void Sorting<T>::insertionSort(T *start, T *end)
{   
    int length = end - start;
    for(int i = 0; i < length; i++){
        T min = start[i];
        int index = i;
        for(int j = i; j < length; j++){
            if(start[j] < min){
                min = start[j];
                index = j;
            }
        }
        T temp = start[i];
        start[i] = start[index];
        start[index] = temp;
    }
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    int length = end - start;
    if(length == 0) return;
    if(length < min_size){
        cout << "Insertion sort: ";
		printArray(start, end);
		insertionSort(start, end);   
    }
    else {
        cout << "Quick sort: ";
        printArray(start, end);
        T *pivot = Partition(start, end);
        hybridQuickSort(start, pivot, min_size);
        hybridQuickSort(pivot + 1, end,min_size);
    }
}

int main(){
    int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
    int min_size = 4;
    Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
}