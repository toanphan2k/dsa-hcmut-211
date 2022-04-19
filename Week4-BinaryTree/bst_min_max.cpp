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
    //HELPING FUNCTIONS
    T minRecur(Node* root){
        if(root->pLeft == NULL) return root->value;
        else{
            return minRecur(root->pLeft)
        }
    }

    T maxRecur(Node* root){
        if(root->pRight == NULL) return root->value;
        else{
            return maxRecur(root->pRight)
        }
    }
    //HELPING FUNCTIONS
    T getMax(){
        return maxRecur(this->root);
    }

    T getMin(){
        return minRecur(this->root);
    }
    // STUDENT ANSWER END
};

int main(){
    BinarySearchTree<int> bst;
    for (int i = 0; i < 10; ++i) {
        bst.add(i);
    }
    cout << bst.getMin() << endl;
    cout << bst.getMax() << endl;
}