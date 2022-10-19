#ifndef __STACK_FRAME_H__
#define __STACK_FRAME_H__

#include <string>
#include <iostream>


#define FLOAT 1
#define INTEGER 0
#define OPERAND_STACK_MAX_SIZE 32
#define LOCAL_VARIABLE_ARRAY_SIZE 256
/*
StackFrame declaration
*/
struct frame{
    float data;
    int type;
};

class StackFrame {
    int opStackMaxSize; // max size of operand stack
    int localVarArrSize; // size of local variable array
public:
    /*
    Constructor of StackFrame
    */
    StackFrame();
    template<class T>
    class SLinkedList {
    public:
        class Node; // Forward declaration
    protected:
        Node* head;
        Node* tail;
        int count;
    public:
        SLinkedList(): head(NULL), tail(NULL), count(0) { };
        ~SLinkedList() { };
        /////////////////////
        void add(const T& data){
            Node* newNode = new Node(data, NULL);
            if(this->count == 0){
                this->head = newNode;
                this->tail = newNode;
            }
            else{
                this->tail->next = newNode;
                this->tail = newNode;
            }
            this->count++;
        }

        void add(int index, const T& data){
            Node* newNode = new Node(data, NULL);
            if(this->count == 0 && index == 0){
                this->head = newNode;
                this->tail = newNode;
                this->count++;
            }
            
            else if(this->count == index && this->count != 0){
                this->tail->next = newNode;
                this->tail = newNode;
                this->count++;
            }
            
            else if(index == 0 && this->count >0){
                newNode->next = this->head;
                this->head = newNode;
                this->count++;
            }
            
            else if(index > 0 && index < this->count){
                Node* temp = this->head;
                for(int i = 0; i < index - 1; i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
                this->count++;
            }    
        }

        int size(){
            return this->count;
        }
        ////////////////////
        T get(int index){
            if(index <0 || index > size()) throw("The index is out of range!");
            if(size() == 0) throw("List is empty");
            else{
                Node* temp = this->head;
                for (int i = 0; i < index; i++) 
                temp = temp->next;
                return temp->data; 
            }
        }

        void set(int index, const T& newData){
            if(index <0 || index > size()) {
                throw("The index is out of range!");
            }
            if(size() == 0) throw("List is empty");
            else {
                Node* temp = this->head;
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                temp->data = newData;
            }            
        }

        int indexOf(const T& item){
            if(isEmpty()) return -1;
            else{
                Node* temp = this->head;
                for (int i = 0; i < this->count; i++){
                    if(temp->data.data == item.data 
                        && temp->data.type == item.type ){
                        return i;
                    }
                    temp = temp->next;
                }
            }
            return -1;                
        }

        bool contains(const T& item){
            if(indexOf(item) == -1) return false;
            else return true;            
        }
        bool isEmpty(){
            return size() == 0;
        }
        ////////////////////
        void clear(){
            while(size() != 0){
                removeAt(0);
            }        
        }
        void removeAt(int index){
            if(index <0 || index >size()) {
                throw("The index is out of range!");
            } 
            if(isEmpty()) throw("List is empty");

            Node* temp = this->head;

            if(index == 0 && size()> 1){
                this->head = temp->next;
                delete temp;
            }


            else if(index == size()-1){
                for(int i = 0; i < size()-2; i ++){
                    temp = temp->next;
                }
                delete this->tail;
                this->tail = temp;
                temp->next = NULL;
            }

            else if(index > 0 && index < size()-1){
                for(int i = 0; i < index - 1; i++){
                    temp = temp->next;
                }
                Node* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                temp2 = NULL;
            }

            else if(index == 0 && size() == 1){
                delete this->head;
                this->head = NULL;
                this->tail = NULL;
            }
            this->count--;
        }

        bool removeItem(const T& item){
            if(indexOf(item) != -1){
                removeAt(indexOf(item));
                return true;
            }
            return false;            
        }
        void toString(){
            Node* temp = this->head;
            std::cout << "----- Stack start -----\n";
            for(int i = 0; i < this->count -1; i++) {
                std::cout << "<" << temp->data.data 
                << "," << temp->data.type << ">\n";

                temp= temp->next;
            }
            std::cout << "<" << temp->data.data 
                << "," << temp->data.type << ">\n" 
                << "----- Stack end -----" << std::endl; 
        }
    public:
        class Node {
        private:
            T data;
            Node* next;
            friend class SLinkedList<T>;
        public:
            Node() {
                next = 0;
            }
            Node(Node* next) {
                this->next = next;
            }
            Node(T data, Node* next) {
                this->data = data;
                this->next = next;
            }
        };
    };

    template<class T>
    class myStack{
    private: 
        int capacity;
    protected:
        SLinkedList<T> initStack;
    public:
        myStack(): capacity((OPERAND_STACK_MAX_SIZE/2) - 1) {}
        void push(T data){
            this->initStack.add(data);
        }
        void pop(){
            this->initStack.removeAt(initStack.size() - 1);
        }
        int stackSize(){
            return initStack.size();
        }
        T top(){
            return this->initStack.get(stackSize() - 1);
        }
        bool isEmpty(){
            return initStack.size() == 0;
        }
        bool isFull(){
            return initStack.size() == capacity;
        }
        void clearStack(){
            return initStack.clear();
        }
    };

    class localvariableArray{
    private:
        int occupiedIndex[LOCAL_VARIABLE_ARRAY_SIZE - 1];
        float localArray[LOCAL_VARIABLE_ARRAY_SIZE - 1];
    public:
        localvariableArray() {
            for(int i = 0; i < LOCAL_VARIABLE_ARRAY_SIZE; i++){
                occupiedIndex[i] = -1;
            }
        }

        bool checkOccupiedIndex(int index){
            if(occupiedIndex[index] == -1) return false;
            else return true;
        }

        bool outOfRange(int index){
            if(index > LOCAL_VARIABLE_ARRAY_SIZE || index < 0) return true;
            else return false;
        }

        int getDataType(int index){
            return (int) localArray[index];
        }

        float removeDataValue(int index){
            occupiedIndex[index] = -1;
            return localArray[index + 1];
        }

        float getValue(int index){
            return localArray[index + 1];
        }

        void setNewValue(float value, int type, int index){
            occupiedIndex[index] = 1;
            localArray[index] = type;
            localArray[index + 1] = value;
        }

    };
    /*
    Run the method written in the testcase
    @param filename name of the file
    */
    void run(std::string filename);
};

#endif // !__STACK_FRAME_H__