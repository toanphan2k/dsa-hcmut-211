//USING RECURSIVE

#include<iostream>
#include<string>
#include<queue>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

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
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
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

    void printOrder(Node* root){
        int height = treeHeight(root);
        for(int i = 1; i <= height; i++){
            printLevel(root, i);
        }
    }

    void printLevel(Node* root, int level){
        if(root == NULL) return;
        else if(level == 1) {
            cout << root->value << " ";
        }
        else if(level > 1){
            printLevel(root->pLeft, level -1);
            printLevel(root->pRight, level -1);
        }
    }
    void BFS(){
        printOrder(this->root);
    }
    // STUDENT ANSWER END
};

int main(){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("",2, 4); // Add to root
    binaryTree.addNode("L",3, 6); // Add to root's left node
    binaryTree.addNode("R",5, 9); // Add to root's right node
    binaryTree.BFS();
    return 0;
}