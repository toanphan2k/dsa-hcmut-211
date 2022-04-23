#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
protected:
    Node *root;
protected:
    int getHeightRec(Node *node)
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
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    //HELPING FUNCTION
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

    Node* insertNode(Node* pNode, T key){
        if(!pNode){
            Node* newNode = new Node(key);
            return newNode;
        }
        
        if(key < pNode->data){
            pNode->pLeft = insertNode(pNode->pLeft, key);
        }
        else if(key >= pNode->data){
            pNode->pRight = insertNode(pNode->pRight, key);
        }

        int bf = BalanceFactor(pNode);

        //LL Rotation
        if(bf < LH && key < pNode->pLeft->data){
            return LLRotation(pNode);
        }
        //RR Rotation
        if(bf > RH && key >= pNode->pRight->data){
            return RRRotation(pNode);
        }
        //LR Rotation
        if(bf < LH && key >= pNode->pLeft->data){
            return LRRotation(pNode);
        }
        //RL Rotation
        if(bf > RH && key < pNode->pRight->data){
            return RLRotation(pNode);
        }
        return pNode;
    }

    void insert(const T &value){
        this->root = insertNode(this->root, value);
    }
    Node* deleteNode(Node* root, T key);
    void remove(const T& value);
    bool search(const T &value);
    void printInorderRec(Node* node);
    bool findRec(Node* node, T i);
    bool search(T value);
    void printInorder();

    //HOMEWORK FUNCTION
    void printInorder(Node* root){
        if(root == NULL) return;

        printInorder(root->pLeft);
        cout << root->data<< " ";
        printInorder(root->pRight);
    }
    string inOrder() {
        // TODO: return the sequence of values of nodes in in-order.
        printInorder(this->root);
        return "";
    }

    int NsmallestSumRec(Node* node, int N, int& count){
        if(!node) return 0;
        if(count > N) return 0;

        int res = NsmallestSumRec(node->pLeft, N, count);
        
        if (count >= N) return res;
        res += node->data;

        count++;
        if (count >= N) return res;

        return res + NsmallestSumRec(node->pRight, N, count);
    }

    int NsmallestSum(int N){
        int k = 0;
        return NsmallestSumRec(this->root, N, k);
    }
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };

};

int main(){
	
AVLTree<int> avl;
int arr[] = {15,1,55,67,86,12,29,38,71,97,21,51,36,19,49,17};
    for (int i = 0; i < 16; i++){
        avl.insert(arr[i]);
    }
avl.printTreeStructure();
avl.inOrder();
std::cout << endl;
cout << avl.NsmallestSum(2);
}

