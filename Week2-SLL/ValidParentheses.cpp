#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

bool isValidParentheses (string s);

bool isValidParentheses (string s){
    /*TODO*/
    stack<char> strStack;
    char topChar;
    if(s.length() == 0){
        return true;
    }
    for(unsigned int i = 0; i < s.length(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            strStack.push(s[i]);
        }
        if(strStack.empty()){
            return false;
        }
        
        else {
            switch(s[i]) {
                case ')':
                    topChar = strStack.top();
                    if (topChar == '[' || topChar == '{') {
                        return false;
                    }
                    strStack.pop();
                    break;
                case ']':
                    topChar = strStack.top();
                    if (topChar == '(' || topChar == '{') {
                        return false;
                    }
                    strStack.pop();
                    //if(strStack.top() == '(') return false;
                    break;
                case '}':
                    topChar = strStack.top();
                    if (topChar == '(' || topChar == '[') {
                        return false;
                    }
                    strStack.pop();
                    //if(strStack.top() == '['|| strStack.top() == '{') return false;
                    break;
            }
        }
    }
    return strStack.empty();
    
}

int main(){
    string s = "[{}](){}";
    if(isValidParentheses(s)) cout << "Valid" << endl;
    else cout << "Invalid";
    return 0;
}