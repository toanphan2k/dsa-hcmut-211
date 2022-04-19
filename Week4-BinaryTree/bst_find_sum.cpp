#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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

    void add(T value){
        root = addNode(root, value);
    }
    // STUDENT ANSWER BEGIN
    bool findRecur(Node* root, T data){
        if(root == NULL) return false;

        if(root->value == data) return true;
        else if(root->value > data){
            return findRecur(root->pLeft, data);
        }
        else if(root->value < data){
            return findRecur(root->pRight, data);
        }
        return false;
    }

    T sumRecur(Node* root, T left, T right){
        if(root == NULL) return 0;

        if(root->value < left){
            return sumRecur(root->pRight, left, right);
        }  
        else if(root->value > right){
            return sumRecur(root->pLeft, left, right);
        }   
        else{
            return root->value + sumRecur(root->pRight, left, right) + sumRecur(root->pLeft, left, right);
        }   
    }
    //HELPING FUCNTION
    bool find(T i) {
        // TODO: return true if value i is in the tree; otherwise, return false.
        return findRecur(this->root, i);
    }

    T sum(T l, T r) {
        // TODO: return the sum of all element in the tree has value in range [l,r].
        return sumRecur(this->root, l, r);
    }
    // STUDENT ANSWER END
};

int main(){
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(i);
    }
    cout << bst.find(7) << endl;
    cout << bst.sum(0, 4) << endl;
    return 0;
}