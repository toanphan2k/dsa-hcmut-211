#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2);
bool checkAnswer(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2);

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2){
    map<int, pair<int, int>> hash;

    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j ++){
            int sum = arr[i] + arr[j];

            if(hash.find(sum) == hash.end()){
                hash[sum] = make_pair(i,j);
            }
            else{
                pair<int, int> temp = hash[sum];
				pair1.first = arr[temp.first];
				pair1.second = arr[temp.second];
				pair2 = make_pair(arr[i],arr[j]);
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[] = { 3, 4, 7 };
    int n = sizeof arr / sizeof arr[0];
    pair<int, int> pair1, pair2;
    if (findPairs(arr, n, pair1, pair2)) {
        if (checkAnswer(arr, n, pair1, pair2)) {
            printf("Your answer is correct.\n");
        }
        else printf("Your answer is incorrect.\n");
    }
    else printf("No pair found.\n");
}