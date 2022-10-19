#include<iostream>
#include<string>
#include<fstream>
using namespace std;


string extractInstruction(string str){
    int size = str.length();
    string instruction;
    for(int i = 0; i < size; i++){
        if(str[i] != ' '){
            instruction += str[i];
        } else{
            break;
        }
    }
    return instruction;
}

string extractValue(string str){
    int size = str.length();
    bool isSpace = false;
    string value;

    for(int i = 0; i < size; i++){
        if(str[i] == ' '){
            isSpace = true;
        }
        if(isSpace){
            value += str[i];
        }
    }
    return value;
}

bool expWithValue(string str){
    for(int i = 0; i < str.length(); i ++){
        if(str[i] == ' ') return true;
    }
    return false;
}

int main(int argc, char* argv[]){
    enum myEnum {iconst, istore, iload};
    myEnum name;
    fstream file;
    string line;
    int lineNumber = 0;
    file.open(argv[1], ios::in);
    while(!file.eof()){
        getline(file, line);
        string instruction;
        string value = "empty";
        instruction = extractInstruction(line);
        if(expWithValue(line)){
            value = extractValue(line);
        }

        
        cout << instruction << " --- " << value << endl;
    }
    file.close();

    return 0;
}