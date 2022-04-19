#include<iostream>
#include<stack>

using namespace std;



int baseballScore(string ops);

int baseballScore(string ops){
/*TODO*/
    int length = ops.length();
    stack<int> stack;
    for(int i = 0; i< length; i++){
        if(ops[i] >= 48 && ops[i] <= 57){
            stack.push((int)ops[i] - 48);
        }

        else if(ops[i] == 'C'){
            if(!stack.empty()) stack.pop();
        }

        else if(ops[i] == 'D'){
            if(!stack.empty()){
                int temp = stack.top()*2;
                stack.push(temp);
            }
        }

        else if(ops[i] == '+'){
            if(stack.size() >= 2) {
                int temp = stack.top();
                stack.pop();
                int sum = stack.top();
                sum += temp;
                stack.push(temp);
                stack.push(sum);
            }
        }
    }

    if(stack.empty()) return 0;
    else{
        int result = 0;
        while(!stack.empty()){
            result += stack.top();
            stack.pop();
        }
        return result;
    }
}

int main(){

    //cout << baseballScore("52CD+");
    cout << baseballScore("524CD9++");
    return 0;
}