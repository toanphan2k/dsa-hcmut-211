
// Recursion Sum//
/////////////////
#include <iostream>
using namespace std;

int sumRe(int *arr, int n);

int sumRe(int *arr, int n){
    if (n < 0) return 0;
    return arr[n] + sumRe(arr, n-1);
}

int main(){
    int n = 4;
    int arr[n] = { 1, 2, 3, 4, 5};

    cout << sumRe(arr, n);
    return 0;

}