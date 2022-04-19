/////// NÀY SỬ DỤNG VÒNG WHILE CHO ADD ///////////

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class BinarySearchTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    //Helping function

    void add(T value){
        //TODO
        Node* curr = root;
        Node* prev;
        if(root == NULL){
            Node* newNode = new Node(value);
            root = newNode;
            return;
        }
        else {
            while(curr != NULL || curr != NULL){
                prev = curr;
                if(curr->value < value){
                    curr = curr->pRight;
                }
                else curr = curr->pLeft;
            }
        }
        if(prev->value < value){
            Node* newNode = new Node(value);
            prev->pRight = newNode;
        }        
        else{
            Node* newNode = new Node(value);
            prev->pLeft = newNode;           
        }
    }

    Node* delNode(Node* node, T value){
        Node* curr = this->root; 
        Node* prev = NULL; 

        while (curr != NULL && curr->value != value) { 
            prev = curr; 
            if (value < curr->value) 
                curr = curr->pLeft; 
            else
                curr = curr->pRight; 
        } 

        if (curr == NULL) { 
            return node; 
        } 

        if (curr->pLeft == NULL || curr->pRight == NULL) { 
            Node* newCurr; 
            if (curr->pLeft == NULL) 
                newCurr = curr->pRight; 
            else
                newCurr = curr->pLeft; 

            if (prev == NULL) 
                return node; 
            if (curr == prev->pLeft) 
                prev->pLeft = newCurr; 
            else
                prev->pRight = newCurr; 
            free(curr); 
        } 
        else { 
            Node* p = NULL; 
            Node* temp; 

            temp = curr->pRight; 
            while (temp->pLeft != NULL) { 
                p = temp; 
                temp = temp->pLeft; 
            } 
            if (p != NULL) 
                p->pLeft = temp->pRight; 
            else
                curr->pRight = temp->pRight; 

            curr->value = temp->value; 
            free(temp); 
        } 
        return node;
    }

    void deleteNode(T value) {
        root = delNode(root, value);
    }


    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    
    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;
    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
};

int main(){
    BinarySearchTree<int> bst;
    bst.add(9);
    bst.add(2);
    bst.add(10);
    bst.add(8);
    cout << bst.inOrder()<<endl;
    bst.add(11);
    bst.deleteNode(11);
    cout << bst.inOrder();  

    return 0;
}