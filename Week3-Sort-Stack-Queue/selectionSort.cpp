#include <iostream>
using namespace std;

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void selectionSort(T *start, T *end);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int length = end - start;
    for(int i = 0; i < length; i++){
        int min = start[i];
        int min_index = i;
        for(int j = i+1; j < length; j++){
            if (start[j] < min)  {
                min = start[j];
                min_index = j;
            }            
        }
        swap(start[i], start[min_index]);
        Sorting<T>::printArray(start, end);
    }
    
}

int main(){
    int arr[] = {9, 2, 8, 1, 0, -2};
    Sorting<int>::selectionSort(&arr[0], &arr[6]);
}