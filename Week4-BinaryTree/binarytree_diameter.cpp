#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

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
        int l = (int)posFromRoot.length();
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

    // Helping functions
    // Height is the number f nodes along the longest
    // path from the root node down to 
    // the farthest leaf node.
    int heightNode(Node* root){
        if(root == NULL) return 0;
        return 1 + max(heightNode(root->pLeft), heightNode(root->pRight));
    }

    int treeDiameter(Node* tree){
        if (tree == NULL) return 0;
        // Tìm height của Left và Right Sub Tree
        int lheight = heightNode(tree->pLeft);
        int rheight = heightNode(tree->pRight);

        // Tìm diameter của mấy cái sub tree xem nó có lớn hơn Height không
        int ldiameter = treeDiameter(tree->pLeft);
        int rdiameter = treeDiameter(tree->pRight);
 
        return max(lheight + rheight + 1,
            max(ldiameter, rdiameter));
    }
    //Helping functions
    int getDiameter(){
        //TODO
        return treeDiameter(root);
    }
};

int main(){
    BinaryTree<int, int> binaryTree;
    binaryTree.addNode("",1, 4);
    binaryTree.addNode("L",2, 6);
    binaryTree.addNode("R",3, 9);
    binaryTree.addNode("LL",4, 10);
    cout << binaryTree.getDiameter();
    return 0;
}