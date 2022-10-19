#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x);

int binarySearch(int arr[], int left, int right, int x)
{
    if(left > right) return -1;
    int mid = (left + right)/2;

    if(arr[mid] == x){
        cout << "We traverse on index: " << mid << endl;
        return mid;
    }
    else if(arr[mid] < x){
        cout << "We traverse on index: " << mid << endl;
        left = mid + 1;
    }
    else{
        cout << "We traverse on index: " << mid << endl;
        right = mid -1;
    }
    return binarySearch(arr, left, right, x);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                    : cout << "Element is present at index " << result;
}