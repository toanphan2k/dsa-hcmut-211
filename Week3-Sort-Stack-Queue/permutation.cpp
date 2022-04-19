#include <iostream>
#include <string>
using namespace std;

bool isPermutation (string a, string b);
int Partition(string str, int start, int end);

void QuickSort(string str, int start, int end) ;

bool isPermutation (string a, string b){

    if(a.length() != b.length()) return false;
    
    int n = a.length();
    QuickSort(a, 0, n);
    QuickSort(b, 0, n);
    
    for(int i = 0; i < a.length(); i ++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

void QuickSort(string str, int start, int end) 
    {
        // TODO
        // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
        if (start < end)
        {
            int i = Partition(str, start, end);    
            //cout << i - start << " ";
            QuickSort(str, start, i);
            QuickSort(str, i + 1, end);
        }
    }
int Partition(string str, int start, int end) 
    {
        // TODO: return the pointer which points to the pivot after rearrange the array.
        int p = str[0];    // pivot
        int i = 0;
        int j = end - start;
        do
        {
            do
            {
                i++;
            } while (str[i] <= p);
            do
            {
                j--;
            } while (str[j]>p);
            swap(str[i], str[j]);
        } while (i<j);
        swap(str[i], str[j]);
        swap(str[0], str[j]);
        return start + j;
    }
int main(){
    string a = "abba";
    string b="baba";
    QuickSort(a, 0, 4);
    cout << a;
    cout << isPermutation(a, b);
    cout << a << endl;
    cout << b << endl;

    return 0;
}