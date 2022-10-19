#include <iostream>
using namespace std;

typedef struct SV {
    int ID;
    int gpa;
} SV;

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

template<typename K, typename V>
class AVLTree {
public:
    class Node; // forward declaration
private:
    Node *root;
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }

    int BalanceFactor(Node* pNode){
        if(pNode==NULL) return 0;
        return getHeightRec(pNode->pRight) - getHeightRec(pNode->pLeft);
    }
    Node* LLRotation(Node* pNode){
        Node* plNode = pNode->pLeft;
        Node* plrNode = plNode->pRight;

        plNode->pRight = pNode;
        pNode->pLeft = plrNode;

        if(root == pNode){
            root = plNode;
        }

        return plNode;
    }

    Node* RRRotation(Node* pNode){
        Node* prNode = pNode->pRight;
        Node* prlNode = prNode->pLeft;

        prNode->pLeft = pNode;
        pNode->pRight = prlNode;

        if(root == pNode){
            root = prNode;
        }

        return prNode;
    }
    Node* LRRotation(Node* pNode){
        pNode->pLeft = RRRotation(pNode->pLeft);
        return LLRotation(pNode);       
    }
    Node* RLRotation(Node* pNode){
        pNode->pRight = LLRotation(pNode->pRight);
        return RRRotation(pNode);
    }

    Node* insertNode(Node* pNode, K key, V value){
        if(!pNode){
            Node* newNode = new Node(key, value);
            return newNode;
        }
        
        if(key < pNode->key){
            pNode->pLeft = insertNode(pNode->pLeft, key, value);
        }
        else if(key >= pNode->key){
            pNode->pRight = insertNode(pNode->pRight, key, value);
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
    //helper fuction here
    void insert(const K &key, const V &value) {
        //TODO
        this->root = insertNode(this->root, key, value);
    }
    void updateHTree(const K &hashValue, const V &value) {
        //TODO
    }
    int sum() {
        //TODO
    }

    //print
    void printPreorder() {
        printPreorder(root);
    }

    void printPreorder(Node *node) {
        if (node == NULL)
            return;
        if (node->value != nullptr)
            cout << node->value->ID << " ";
        printPreorder(node->pLeft);
        printPreorder(node->pRight);
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        Node(K key) : key(key), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};