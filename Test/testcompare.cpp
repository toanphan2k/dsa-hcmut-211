#include<iostream>
#include<string>

using namespace std;

int main(){
    string str1 = "a";
    string str2 = "A";

    string str3 = "hi";
    string str4 = "hi";
    if(str1 > str2){
        cout << "greater\n";
    }else{
        cout << "smaller\n";
    }

    if(str3 == str4){
        cout << "equal\n";
    }
    return 0;
}