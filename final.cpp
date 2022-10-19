#include <iostream>
using namespace std;
template <typename T>
class BSTree{
public:
    class Node; // forward declaration
private:
    Node* root = nullptr;
public:
    BSTree() : root(nullptr) {}
    ~BSTree(){}
    // helper function here
    void insertFIFO(T data) {
        add(data);
    };

    T sumLeft(){
        return sumRecur(this->root->pLeft);
    };

    T sumRecur(Node* root){
        if(root == NULL) return 0;
        return root->data + sumRecur(root->pRight) + sumRecur(root->pLeft);
    }

    Node* addNode(Node* root, T value){
        if(root == NULL) {
            Node* newNode = new Node(value);
            return newNode;
        }

        if(root->data > value){
            root->pLeft = addNode(root->pLeft, value);
        }

        if(root->data <= value){
            root->pRight = addNode(root->pRight, value);
        }
        return root;       
    }

    Node* delNode(Node* root, T value){
        if(root == NULL){
            return root;
        }

        if(root->data < value){
            root->pRight = delNode(root->pRight, value);
        }
        else if(root->data > value){
            root->pLeft = delNode(root->pLeft, value);
        }
        else if(root->data == value && root->pLeft == NULL){
            Node* temp = root->pRight;
            free(root);
            return temp;
        }
        else if(root->data == value && root->pRight == NULL){
            Node* temp = root->pLeft;
            free(root);
            return temp;
        }
        else if(root->data == value && root->pRight != NULL && root->pLeft != NULL){
            Node* temp = minValueNode(root->pRight);
            root->data = temp->data;
            root->pRight = delNode(root->pRight, temp->data);
        }
        return root;
    }

    void add(T value){
        root = addNode(root, value);
    }

    void deleteNode(T value) {
        root = delNode(root, value);
    }

    int findADepth(Node *node){
        int d = 0;
        while (node != NULL)
        {
            d++;
            node = node->pLeft;
        }
        return d;
    }
    bool isPerfectRec(Node* root, int d, int level = 0){

        if (root == NULL)
            return true;
        if (root->pLeft == NULL && root->pRight == NULL)
            return (d == level+1);
        if (root->pLeft == NULL || root->pRight == NULL)
            return false;

        return isPerfectRec(root->pLeft, d, level+1) &&
            isPerfectRec(root->pRight, d, level+1);
    }

    bool isPerfect(Node *root){
        int d = findADepth(root);
        return isPerfectRec(root, d);
    }

    void inorder( Node* root)
    {
        if (root != NULL) {
            inorder(root->pLeft);
            cout << root->data << " ";
            inorder(root->pRight);
        }
    }
    void printIn()
    {
        inorder(root);
    }
public:
    class Node
    {
    private:
        T data;
        Node *pLeft;
        Node *pRight;
        friend class BSTree<T>;
    public:
        Node(): pLeft(0), pRight(0) {};
        Node(T data): data(data), pLeft(0), pRight(0) {};
    };
};

int main(){
    BSTree<int> tree;
    BSTree<int>::Node node();
    int arr[12] = {30,19,31,6,18,20,28,16,11,13,14,7};
    for(int i = 0; i < 12; i++)
    {
        tree.insertFIFO(arr[i]);
    }
    tree.printIn();
    cout << endl << tree.sumLeft();
    return 0;
}