#include<iostream>
template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    T       removeAt(int index);
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };

};

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if(index <0 || index >size()) {
        throw out_of_range("The index is out of range!");
    } 
    if(empty()) throw("List is empty");

    Node* temp = this-> head;
    T dataDelete;  
    
    if(index == 0 && size()> 1){
        dataDelete = temp->data;
        this->head = temp->next;
        delete temp;
    }  
    else if(index == size()-1){
        for(int i = 0; i < size()-2; i ++){
            temp = temp->next;
        }
        dataDelete = this->tail->data;
        delete this->tail;
        this->tail = temp;
        temp->next = NULL;
    }
    else if(index == 0 && size() == 1){
        dataDelete = this->head->data;
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    else if(index > 0 && index < size()-1){
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        dataDelete = temp->data;
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
        delete temp;
    }    
    
    this->count--;
    return dataDelete;
}