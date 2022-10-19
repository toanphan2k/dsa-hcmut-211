#include "StackFrame.h"
#include <iostream>
#include <fstream>
#include "errors.h"
#include "constants.h"

using namespace std;

string extractInstruction(string str);
string extractValue(string str);
bool expWithValue(string str);

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
    for(unsigned int i = 0; i < str.length(); i ++){
        if(str[i] == ' ') return true;
    }
    return false;
}

StackFrame::StackFrame() : opStackMaxSize(OPERAND_STACK_MAX_SIZE), localVarArrSize(LOCAL_VARIABLE_ARRAY_SIZE) {}

void StackFrame::run(string filename) {
    myStack<frame> stack;
    localvariableArray array;

    fstream file;
    string line;

    int lineNumber = 0;

    file.open(filename, ios::in);
    while(!file.eof()){
        getline(file, line);
        lineNumber ++; 
        string instruction;
        string value;
        instruction = extractInstruction(line);
        value = extractValue(line);

        // Arithmetic Instructions:: iadd - 1
        if(instruction == "iadd"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();
                
                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    frame newData;
                    newData.data = int(data1.data + data2.data);
                    newData.type = INTEGER;
                    stack.push(newData);
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
        }
        // Arithmetic Instructions:: iadd - 2
        else if(instruction == "fadd"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                frame newData;
                newData.data = data1.data + data2.data;
                newData.type = FLOAT;
                stack.push(newData);
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
        }
        // Arithmetic Instructions:: isub - 3
        else if(instruction == "isub"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();
                
                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    frame newData;
                    newData.data = int(data2.data - data1.data);
                    newData.type = INTEGER;
                    stack.push(newData);
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
        } 
        // Arithmetic Instructions:: fsub - 4    
        else if(instruction == "fsub"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                frame newData;
                newData.data = float(data2.data - data1.data);
                newData.type = FLOAT;
                stack.push(newData);
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
        } 
        // Arithmetic Instructions:: imul - 5       
        else if(instruction == "imul"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();
                
                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    frame newData;
                    newData.data = int(data1.data * data2.data);
                    newData.type = INTEGER;
                    stack.push(newData);
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
        }
        // Arithmetic Instructions:: fmul - 6
        else if(instruction == "fmul"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                frame newData;
                newData.data = data1.data * data2.data;
                newData.type = FLOAT;
                stack.push(newData);
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }           
        }    
        // Arithmetic Instructions:: idiv - 7
        else if(instruction == "idiv"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();
                
                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    if(data1.data == 0){
                        stack.clearStack();
                        file.close();
                        throw DivideByZero(lineNumber);
                    }
                    else{
                        frame newData;
                        newData.data = int(data2.data / data1.data);
                        newData.type = INTEGER;
                        stack.push(newData);
                    }
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }            
        }   
        // Arithmetic Instructions:: fdiv - 8
        else if(instruction == "fdiv"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();
                
                if(data1.data == 0){
                    stack.clearStack();
                    file.close();
                    throw DivideByZero(lineNumber);
                }
                else{
                    frame newData;
                    newData.data = float(data2.data / data1.data);
                    newData.type = FLOAT;
                    stack.push(newData);
                }
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }            
        }         
        // Arithmetic Instructions:: irem - 9
        else if(instruction == "irem"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();
                
                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    if(data1.data == 0){
                        stack.clearStack();
                        file.close();
                        throw DivideByZero(lineNumber);
                    }
                    else{
                        frame newData;
                        newData.data = int(data2.data - int((data2.data / data1.data)*data1.data));
                        newData.type = INTEGER;
                        stack.push(newData);
                    }
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }            
        }  
        // Arithmetic Instructions:: ineg - 10
        else if(instruction == "ineg"){
            if(stack.stackSize() > 0){
                frame data1;
                data1 = stack.top();
                stack.pop();
                
                if(data1.type == INTEGER){
                    frame newData;
                    newData.data = int(-data1.data);
                    newData.type = INTEGER;
                    stack.push(newData);
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }     
        } 
        // Arithmetic Instructions:: fneg - 11
        else if(instruction == "fneg"){
            if(stack.stackSize() > 0){
                frame data1;
                data1 = stack.top();
                stack.pop();
                
                frame newData;
                newData.data = float(-data1.data);
                newData.type = FLOAT;
                stack.push(newData);
            }
            else {
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }      
        }       
        // Arithmetic Instructions:: iand - 12
        else if(instruction == "iand"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    int result = (int)data1.data & (int)data2.data;
                    frame newData;
                    newData.data = result;
                    newData.type = INTEGER;
                    stack.push(newData);
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);     
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }
        }      
        // Arithmetic Instructions:: ior - 13
        else if(instruction == "ior"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    int result = (int)data1.data | (int)data2.data;
                    frame newData;
                    newData.data = result;
                    newData.type = INTEGER;
                    stack.push(newData);
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);     
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }   
        }          
        // Arithmetic Instructions:: ieq - 14
        else if(instruction == "ieq"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    if(data1.data == data2.data){
                        frame newData;
                        newData.data = 1;
                        newData.type = INTEGER;
                        stack.push(newData);
                    }
                    else{
                        frame newData;
                        newData.data = 0;
                        newData.type = INTEGER;
                        stack.push(newData);             
                    }
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);     
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }     
        } 
        // Arithmetic Instructions:: feq - 15
        else if(instruction == "feq"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                if(data1.data == data2.data){
                    frame newData;
                    newData.data = 1;
                    newData.type = FLOAT;
                    stack.push(newData);
                }
                else{
                    frame newData;
                    newData.data = 0;
                    newData.type = FLOAT;
                    stack.push(newData);             
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }   
        } 
        // Arithmetic Instructions:: ineq - 16
        else if(instruction == "ineq"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    if(data1.data != data2.data){
                        frame newData;
                        newData.data = 1;
                        newData.type = INTEGER;
                        stack.push(newData);
                    }
                    else{
                        frame newData;
                        newData.data = 0;
                        newData.type = INTEGER;
                        stack.push(newData);             
                    }
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);     
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            } 
        }
        // Arithmetic Instructions:: fneq - 17
        else if(instruction == "fneq"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop();

                if(data1.data != data2.data){
                    frame newData;
                    newData.data = 1;
                    newData.type = FLOAT;
                    stack.push(newData);
                }
                else{
                    frame newData;
                    newData.data = 0;
                    newData.type = FLOAT;
                    stack.push(newData);             
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            } 
        }
        // Arithmetic Instructions:: ilt - 18
        else if(instruction == "ilt"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop(); 

                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    if(data2.data < data1.data){
                        frame newData;
                        newData.data = 1;
                        newData.type = INTEGER;
                        stack.push(newData);
                    }
                    else{
                        frame newData;
                        newData.data = 0;
                        newData.type = INTEGER;
                        stack.push(newData);             
                    }
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);   
                }                
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }
        }        
        // Arithmetic Instructions:: flt - 19
        else if(instruction == "flt"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop(); 

                if(data2.data < data1.data){
                    frame newData;
                    newData.data = 1;
                    newData.type = FLOAT;
                    stack.push(newData);
                }
                else{
                    frame newData;
                    newData.data = 0;
                    newData.type = FLOAT;
                    stack.push(newData);             
                }              
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }
        }    
        // Arithmetic Instructions:: igt - 20
        else if(instruction == "igt"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop(); 

                if((data1.type == INTEGER) && (data2.type == INTEGER)){
                    if(data2.data > data1.data){
                        frame newData;
                        newData.data = 1;
                        newData.type = INTEGER;
                        stack.push(newData);
                    }
                    else{
                        frame newData;
                        newData.data = 0;
                        newData.type = INTEGER;
                        stack.push(newData);             
                    }
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);   
                }                
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }
        }   
        // Arithmetic Instructions:: fgt - 21
        else if(instruction == "fgt"){
            if(stack.stackSize() > 1){
                frame data1;
                frame data2;
                data1 = stack.top();
                stack.pop();
                data2 = stack.top();
                stack.pop(); 

                if(data2.data > data1.data){
                    frame newData;
                    newData.data = 1;
                    newData.type = FLOAT;
                    stack.push(newData);
                }
                else{
                    frame newData;
                    newData.data = 0;
                    newData.type = FLOAT;
                    stack.push(newData);             
                }              
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);                
            }
        }      
        // Arithmetic Instructions:: ibnot - 22
        else if(instruction == "ibnot"){
            if(stack.stackSize() > 0){
                frame data1;
                data1 = stack.top();
                stack.pop();

                if(data1.type == INTEGER){
                    if(data1.data == 0){
                        frame newData;
                        newData.data = 1;
                        newData.type = INTEGER;
                        stack.push(newData);
                    }
                    else{
                        frame newData;
                        newData.data = 0;
                        newData.type = INTEGER;
                        stack.push(newData);                       
                    }
                }
                else{
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);   
                }
            }
            else{
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);   
            }
        }          
        // Load & Store Instructions:: iconst <value> - 23
        else if(instruction == "iconst"){
            if(stack.isFull()){
                stack.clearStack();
                file.close();
                throw StackFull(lineNumber);
            }
            else{
                frame newData;
                newData.data = stoi(value);
                newData.type = INTEGER;
                stack.push(newData);
            }
        }
        // Load & Store Instructions:: fconst <value>- 24
        else if(instruction == "fconst"){
            if(stack.isFull()){
                stack.clearStack();
                file.close();
                throw StackFull(lineNumber);
            }
            else{
                frame newData;
                newData.data = stof(value);
                newData.type = FLOAT;
                stack.push(newData);
            }
        }        
        // Load & Store Instructions:: iload <index> - 25
        else if(instruction == "iload"){
            int index = stoi(value);
            if(array.outOfRange(index)){
                stack.clearStack();
                file.close();
                throw ArrayOutOfRange(lineNumber);
            }
            else{
                if(!array.checkOccupiedIndex(index)){
                    stack.clearStack();
                    file.close();
                    throw UndefinedVariable(lineNumber);
                }
                else{
                    if(array.getDataType(index) != INTEGER){
                        stack.clearStack();
                        file.close();
                        throw TypeMisMatch(lineNumber);
                    }
                    else{
                        if(stack.isFull()){
                            stack.clearStack();
                            file.close();
                            throw StackFull(lineNumber);
                        }
                        else{
                            frame newData;
                            newData.type = INTEGER;
                            newData.data = (int) array.getValue(index);
                            stack.push(newData);
                        }
                    }
                }
            }
        }
        // Load & Store Instructions:: fload <index> - 26
        else if(instruction == "fload"){
            int index = stoi(value);
            if(array.outOfRange(index)){
                stack.clearStack();
                file.close();
                throw ArrayOutOfRange(lineNumber);
            }
            else{
                if(!array.checkOccupiedIndex(index)){
                    stack.clearStack();
                    file.close();
                    throw UndefinedVariable(lineNumber);
                }
                else{
                    if(array.getDataType(index) != FLOAT){
                        stack.clearStack();
                        file.close();
                        throw TypeMisMatch(lineNumber);
                    }
                    else{
                        if(stack.isFull()){
                            stack.clearStack();
                            file.close();
                            throw StackFull(lineNumber);
                        }
                        else{
                            frame newData;
                            newData.type = FLOAT;
                            newData.data = array.getValue(index);
                            stack.push(newData);
                        }
                    }
                }
            }
        }             
        // Load & Store Instructions:: istore <index> - 27
        else if(instruction == "istore"){
            int index = stoi(value);
            if(array.outOfRange(index)){
                stack.clearStack();
                file.close();
                throw ArrayOutOfRange(lineNumber);
            }
            else{
                if(stack.isEmpty()){
                    stack.clearStack();
                    file.close();
                    throw StackEmpty(lineNumber);
                }
                else{
                    frame newData = stack.top();
                    stack.pop();
                    if(newData.type != INTEGER){
                        stack.clearStack();
                        file.close();
                        throw TypeMisMatch(lineNumber);
                    }
                    else{
                        array.setNewValue(newData.data, newData.type, index);
                    }
                }
            }
        }      
        // Load & Store Instructions:: fstore <index> - 28
        else if(instruction == "fstore"){
            int index = stoi(value);
            if(array.outOfRange(index)){
                stack.clearStack();
                file.close();
                throw ArrayOutOfRange(lineNumber);
            }
            else{
                if(stack.isEmpty()){
                    stack.clearStack();
                    file.close();
                    throw StackEmpty(lineNumber);
                }
                else{
                    frame newData = stack.top();
                    stack.pop();
                    if(newData.type != FLOAT){
                        stack.clearStack();
                        file.close();
                        throw TypeMisMatch(lineNumber);
                    }
                    else{
                        array.setNewValue(newData.data, newData.type, index);
                    }
                }
            }
        }      
        // Type Conversion Instructions:: i2f - 29
        else if(instruction == "i2f"){
            if(stack.stackSize() <= 0){
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
            else{
                frame newData = stack.top();
                stack.pop();
                if(newData.type != INTEGER){
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
                else{
                    newData.type = FLOAT;
                    stack.push(newData);
                }
            }
        } 
        // Type Conversion Instructions:: f2i - 30
        else if(instruction == "f2i"){
            if(stack.stackSize() <= 0){
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
            else{
                frame newData = stack.top();
                stack.pop();
                if(newData.type != FLOAT){
                    stack.clearStack();
                    file.close();
                    throw TypeMisMatch(lineNumber);
                }
                else{
                    newData.type = INTEGER;
                    stack.push(newData);
                }
            }
        }     
        // Operand Stack Management Instructions: top - 31
        else if(instruction == "top"){
            if(stack.isEmpty()){
                stack.clearStack();
                file.close();
                throw StackEmpty(lineNumber);
            }
            else{
                frame topData;
                topData = stack.top();
                if(topData.type == INTEGER){
                    cout << (int)topData.data << "\n";
                }
                else if(topData.type == FLOAT){
                    cout << (float)topData.data << "\n";
                }
            }
        }
        // Local Variable Management Instructions:: val <index> - 32
        else if(instruction == "val"){
            int index = stoi(value);
            if(array.outOfRange(index)){
                stack.clearStack();
                file.close();
                throw ArrayOutOfRange(lineNumber);
            }
            else{
                if(!array.checkOccupiedIndex(index)){
                    stack.clearStack();
                    file.close();
                    throw UndefinedVariable(lineNumber);
                }
                else{
                    if(array.getDataType(index) == INTEGER){
                        cout << (int)array.getValue(index) << "\n";
                    }
                    else{
                        cout << (float)array.getValue(index) << "\n";
                    }
                }
            }
        }
    }
    file.close();
}