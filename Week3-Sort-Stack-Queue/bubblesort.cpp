#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};
template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (this->size() == 0 || this->size() == 1) return;

    //Node* sorted = this->head;
    for(int i = 0; i < this->size() - 1; i++){
        bool isSwapped = false;
        Node* sorted = this->head;
        Node* start = sorted;
        for(int j = 0; j < this->size() - i - 1; j ++){ 
            Node* p1 = start;
            Node* p2 = p1->next;
            if(p1->data > p2->data){
                T temp = p1->data;
                p1->data = p2->data;
                p2->data = temp;
                isSwapped = true;
            } 
            start = start->next;
        }
        sorted = sorted->next;
        if(isSwapped){
            this-> printList();
        } 
        else break;
    }
}

int main(){
    int arr[] = {9, 2, 8, 4, 1, 11, 5, 20, 18};
    SLinkedList<int> list;
    for(int i = 0; i <int(sizeof(arr))/4;i++)
        list.add(arr[i]);
    list.bubbleSort();
}