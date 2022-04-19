#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN
    int treeHeight(Node* root){
        if(root == NULL){
            return 0;
        }
        int lHeight = treeHeight(root->pLeft);
        int rHeight = treeHeight(root->pRight);

        return max(lHeight+1, rHeight+1);
    }

    void printPostorder(Node* root){
        if(root == NULL) return;

        printPostorder(root->pLeft);
        printPostorder(root->pRight);
        cout<< root->value << " ";
    }

    void printInorder(Node* root){
        if(root == NULL) return;

        printInorder(root->pLeft);
        cout << root->value<< " ";
        printInorder(root->pRight);
    }

    void printPreorder(Node* root){
        if(root == NULL) return;

        cout<<root->value<< " ";
        printPreorder(root->pLeft);
        printPreorder(root->pRight);
    }

    int getHeight() {
        // TODO: return height of the binary tree.
        return treeHeight(this->root);
    }

    string preOrder() {
        // TODO: return the sequence of values of nodes in pre-order.
        printPreorder(this->root);
        return "";
    }

    string inOrder() {
        // TODO: return the sequence of values of nodes in in-order.
        printInorder(this->root);
        return "";
    }

    string postOrder() {
        // TODO: return the sequence of values of nodes in post-order.
        printPostorder(this->root);
        return "";      
    }
    // STUDENT ANSWER END
};

int main(){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("", 2, 4); // Add to root
    binaryTree.addNode("L", 3, 6); // Add to root's left node
    binaryTree.addNode("R", 5, 9); // Add to root's right node

    cout << binaryTree.getHeight() << endl;
    cout << binaryTree.preOrder() << endl;
    cout << binaryTree.inOrder() << endl;
    cout << binaryTree.postOrder() << endl;
}