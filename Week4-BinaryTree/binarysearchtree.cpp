////// USING RECURSIVE ///////
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


    Node* minValueNode(Node* node){
        Node* curr = node;
        while (curr && curr->pLeft != NULL){
            curr = curr->pLeft;
        }
        return curr;
    }
    Node* addNode(Node* root, T value){
        if(root == NULL) {
            Node* newNode = new Node(value);
            return newNode;
        }

        if(root->value > value){
            root->pLeft = addNode(root->pLeft, value);
        }

        if(root->value <= value){
            root->pRight = addNode(root->pRight, value);
        }
        return root;       
    }

    Node* delNode(Node* root, T value){
        if(root == NULL){
            return root;
        }

        if(root->value < value){
            root->pRight = delNode(root->pRight, value);
        }
        else if(root->value > value){
            root->pLeft = delNode(root->pLeft, value);
        }
        else if(root->value == value && root->pLeft == NULL){
            Node* temp = root->pRight;
            free(root);
            return temp;
        }
        else if(root->value == value && root->pRight == NULL){
            Node* temp = root->pLeft;
            free(root);
            return temp;
        }
        else if(root->value == value && root->pRight != NULL && root->pLeft != NULL){
            Node* temp = minValueNode(root->pRight);
            root->value = temp->value;
            root->pRight = delNode(root->pRight, temp->value);
        }

        return root;
    }
    void add(T value){
        root = addNode(root, value);
    }

    void deleteNode(T value) {
        //TODO
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
    /*
    BinarySearchTree<int> bst;
    bst.add(9);
    bst.add(2);
    bst.add(10);
    bst.deleteNode(9);
    cout << bst.inOrder();
    */

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