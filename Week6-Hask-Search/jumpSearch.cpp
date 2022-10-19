#include <iostream>
#include <math.h>
using namespace std;

int jumpSearch(int arr[], int x, int n);

int jumpSearch(int arr[], int x, int n){
    int step = sqrt(n);
    int prev = 0;
    for(int i = 0; i < n; i += step){
        if(arr[i] <= x) prev = i;
        if(arr[i] == x ){
            cout << i;
            return i;
        }
        cout << i << " ";
        if(arr[i] > x ) break;
    }

    for(int i = prev; i < prev + step; i ++){
        if(arr[i] == x){
            
        }
    }
}

int main(){
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);

    if (index != -1) {
        cout << "\nNumber " << x << " is at index " << index;
    }
    else {
        cout << "\n" << x << " is not in array!";
    }
}