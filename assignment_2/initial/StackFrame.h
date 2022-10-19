#ifndef __STACK_FRAME_H__
#define __STACK_FRAME_H__

#include <string>
#include <stack>
#include "constants.h"
#include <iostream>

#define FLOAT 1
#define INTEGER 0
#define OPERAND_STACK_MAX_SIZE 32
#define LOCAL_VARIABLE_ARRAY_SIZE 256

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

struct frame{
    float data;
    int type;
};
/*
StackFrame declaration
*/
class StackFrame {
    int opStackMaxSize; // max size of operand stack
    int localVarSpaceSize; // size of local variable array
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
        myStack(): capacity(OPERAND_STACK_MAX_SIZE/2) {}
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

    template<class T, class K>
    class AVLTree {
    public:
        class AVLNode;
    protected:
        AVLNode *root;
    protected:
        int getHeightRec(AVLNode *node)
        {
            if (node == NULL)
                return 0;
            int lh = this->getHeightRec(node->pLeft);
            int rh = this->getHeightRec(node->pRight);
            return (lh > rh ? lh : rh) + 1;
        }
    public:
        AVLTree() : root(nullptr) {}
        ~AVLTree(){}

        int getHeight(){
            return this->getHeightRec(this->root);
        }

        int BalanceFactor(AVLNode* pNode){
            if(pNode==NULL) return 0;
            return getHeightRec(pNode->pRight) - getHeightRec(pNode->pLeft);
        }

        AVLNode* LLRotation(AVLNode* pNode){
            AVLNode* plNode = pNode->pLeft;
            AVLNode* plrNode = plNode->pRight;

            plNode->pRight = pNode;
            pNode->pLeft = plrNode;

            if(root == pNode){
                root = plNode;
            }

            return plNode;
        }

        AVLNode* RRRotation(AVLNode* pNode){
            AVLNode* prNode = pNode->pRight;
            AVLNode* prlNode = prNode->pLeft;

            prNode->pLeft = pNode;
            pNode->pRight = prlNode;

            if(root == pNode){
                root = prNode;
            }

            return prNode;
        }

        AVLNode* LRRotation(AVLNode* pNode){
            pNode->pLeft = RRRotation(pNode->pLeft);
            return LLRotation(pNode);       
        }

        AVLNode* RLRotation(AVLNode* pNode){
            pNode->pRight = LLRotation(pNode->pRight);
            return RRRotation(pNode);
        }

        AVLNode* insertNode(AVLNode* pNode, K key, T data){
            if(!pNode){
                AVLNode* newNode = new AVLNode(data, key);
                return newNode;
            }
            
            if(key < pNode->key){
                pNode->pLeft = insertNode(pNode->pLeft, key, data);
            }
            else if(key >= pNode->key){
                pNode->pRight = insertNode(pNode->pRight, key, data);
            }

            int bf = BalanceFactor(pNode);

            //LL Rotation
            if(bf < LH && key < pNode->pLeft->key){
                return LLRotation(pNode);
            }
            //RR Rotation
            if(bf > RH && key >= pNode->pRight->key){
                return RRRotation(pNode);
            }
            //LR Rotation
            if(bf < LH && key >= pNode->pLeft->key){
                return LRRotation(pNode);
            }
            //RL Rotation
            if(bf > RH && key < pNode->pRight->key){
                return RLRotation(pNode);
            }
            return pNode;
        }

        void insert(const K &key, const T& data){
            this->root = insertNode(this->root, key, data);
        }

        AVLNode* minValueNode(AVLNode* pNode){
            AVLNode* curr = pNode;
            while (curr && curr->pLeft != NULL){
                curr = curr->pLeft;
            }
            return curr;
        }

        AVLNode* maxValueNode(AVLNode* pNode){
            AVLNode* curr = pNode;
            while (curr && curr->pRight != NULL){
                curr = curr->pRight;
            }
            return curr;
        }

        AVLNode* deleteNodeRec(AVLNode* pNode, K key){
            if(!pNode){
                return pNode;
            }

            if(pNode->data < key){
                pNode->pRight = deleteNodeRec(pNode->pRight, key);
            }
            else if(pNode->data > key){
                pNode->pLeft = deleteNodeRec(pNode->pLeft, key);
            }
            else if(pNode->key == key && pNode->pLeft == NULL){
                AVLNode* temp = pNode->pRight;
                free(pNode);
                return temp;
            }
            else if(pNode->key == key && pNode->pRight == NULL){
                AVLNode* temp = pNode->pLeft;
                free(pNode);
                return temp;
            }
            else if(pNode->key == key && pNode->pRight != NULL && pNode->pLeft != NULL){
                AVLNode* temp = maxValueNode(pNode->pLeft);
                pNode->data = temp->data;
                pNode->key = temp->key;
                pNode->pLeft = deleteNodeRec(pNode->pLeft, temp->key);
            }

            if (pNode == NULL){
                return pNode;
            }

            int bf = BalanceFactor(pNode);
            //LL Rotation
            if(bf < LH && BalanceFactor(root->pLeft) <= EH){
                return LLRotation(pNode);
            }
            //RR Rotation
            if(bf > RH && BalanceFactor(root->pLeft) >= EH){
                return RRRotation(pNode);
            }
            //LR Rotation
            if(bf < LH && BalanceFactor(root->pLeft) < EH){
                return LRRotation(pNode);
            }
            //RL Rotation
            if(bf > RH && BalanceFactor(root->pLeft) > EH){
                return RLRotation(pNode);
            }
            return pNode;
        }

        void remove(const K& key){
            this->root = deleteNodeRec(this->root, key);
        }

        AVLNode* search(const K &key){
            return searchRec(this->root, key);
        }

        AVLNode* searchRec(AVLNode* pNode, K key){
            if (!pNode) return NULL;
            else if (pNode->key == key) return pNode;
            else if (pNode->key > key) return searchRec(pNode->pLeft, key);
            else return searchRec(pNode->pRight, key);
        }

        void destroyTree() {
            destroyTreeRec(this->root);
        }

        void destroyTreeRec(AVLNode* pNode){
            if (pNode == NULL) return;
            destroyTreeRec(pNode->pLeft);
            destroyTreeRec(pNode->pRight);
            delete pNode;
            pNode = NULL;
        }

        AVLNode* searchParentRec(AVLNode* pNode, K key){
            if (pNode == NULL) return NULL;
            if (pNode->pLeft->key == key) {
                return pNode;
            }
            else if(pNode->pRight->key == key){
                return pNode;
            }
            else{
                searchParentRec(pNode->pLeft, key);
                searchParentRec(pNode->pRight, key);
            }
            return NULL;
        }
        AVLNode* searchParent(K key){
            AVLNode* temp = searchParentRec(this->root, key);
            if(!temp) return NULL;
            std::cout << temp->key;
            if (temp->key == key) return NULL;
            return temp;
        }

        int countNodeRec(AVLNode* pNode){
            if (pNode == NULL)
                return 0;
            else {
                return 1 + countNodeRec(pNode->pLeft) + countNodeRec(pNode->pRight);
            }
        }
        int getSize(){
            return countNodeRec(this->root);
        }

        class AVLNode
        {
        private:
            T data;
            K key;
            AVLNode *pLeft, *pRight;
            BalanceValue balance;
            friend class AVLTree<T, K>;

        public:
            AVLNode(T frame, K value) : data(frame), key(value), pLeft(NULL), pRight(NULL), balance(EH) {}
            ~AVLNode() {}

            T getFrame(){
                return data;
            }
            K getKey(){
                return key;
            }
        };
    };

    /*
    Run the method written in the testcase
    @param filename name of the file
    */
    void run(std::string filename);
};

#endif // !__STACK_FRAME_H__