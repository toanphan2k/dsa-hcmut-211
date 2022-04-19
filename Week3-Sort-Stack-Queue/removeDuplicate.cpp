#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

string removeDuplicates(string S);


string removeDuplicates(string S){
    /*TODO*/
    stack<char> myStack; ;
    for(int i = 0; i < S.length(); i++){
        if(myStack.empty() || S[i] != myStack.top()) {
            myStack.push(S[i]);
        }
        else myStack.pop();
    }

    string str = "";
    while (!myStack.empty()) {
        str = myStack.top() + str;
        myStack.pop();
    }    
    return str;
}

int main(){
    cout << removeDuplicates("abbaca");
    return 0;
}