#include<iostream>
#include<string.h>

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
    SLinkedList(): head(NULL), tail(NULL), count(0) { };
    ~SLinkedList() { };
    void    toString();
    /////////////////////Q3
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    ////////////////////Q4
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
    bool    empty();
    ////////////////////Q5
    void    clear();
    T       removeAt(int index);
    bool    removeItem(const T& item);     

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
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};
/////////////////////////////////////// Question 3
template <class T>
void SLinkedList<T>::toString() {
    Node* temp = this->head;
    cout << "[";
    for(int i = 0; i < this->count -1; i++) {
        cout << temp->data << "-";
        temp= temp->next;
    }
    cout << temp->data << "]" << endl;
}


template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e, NULL);
    if(this->count == 0){
        this->head = newNode;
        this->tail = newNode;
    }
    else {
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->count ++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    Node* newNode = new Node(e, NULL);
    if(this->count == 0 && index == 0){
        this->head = newNode;
        this->tail = newNode;
        this->count++;
    }
    
    else if(this->count == index && this->count != 0){
        this->tail->next = newNode;
        this->tail = newNode;
        this->count++;
    }
    
    else if(index == 0 && this->count >0){
        newNode->next = this->head;
        this->head = newNode;
        this->count++;
    }
    
    else if(index > 0 && index < this->count){
        Node* temp = this->head;
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        this->count++;
    }   
}

template <class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}
////////////////////////////////////////////// Question 4

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if(index <0 || index > size()) throw out_of_range("The index is out of range!");
    if(size() == 0) throw("List is empty");
    else {
        Node* temp = this->head;
        for (int i = 0; i < index; i++) 
        temp = temp->next;
        return temp->data; 
    }
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if(index <0 || index > size()) {
        throw out_of_range("The index is out of range!");
    }
    if(size() == 0) throw("List is empty");
    else {
        Node* temp = this->head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = e;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if(size() == 0){
        return true;
    } 
    else return false;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (empty()) return -1;
    else {
        Node* temp = this->head;
        for (int i = 0; i < this->count; i++) {
            if(temp->data == item) {
                return i;
            }
            temp = temp->next;
        }
    }
    return -1;   
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    if(indexOf(item) == -1) return false;
    else return true;
}
////////////////////////////////////////////// Question 5
template<class T>
T SLinkedList<T>::removeAt(int index){
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

    else if(index > 0 && index < size()-1){
        for(int i = 0; i < index - 1; i++){
            temp = temp->next;
        }
        Node* temp2 = temp->next;
        dataDelete = temp2->data;
        temp->next = temp2->next;
        delete temp2;
        temp2 = NULL;
    }

    else if(index == 0 && size() == 1){
        dataDelete = this->head->data;
        delete this->head;
        this->head = NULL;
        this->tail = NULL;
    }
    this->count--;
    return dataDelete;
}

template<class T>
bool SLinkedList<T>::removeItem(const T& item){
    if(indexOf(item) != -1){
        removeAt(indexOf(item));
        return true;
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    while(size() != 0){
        removeAt(0);
    }
}

int main(){
    SLinkedList<int> list;
    int size = 10;

    for(int index = 0; index < size; index++){
        list.add(index);
    }

    list.toString(); 

    cout << list.get(0)<< endl;

    list.set(0, 10);
    list.toString(); 

    if(list.empty()) cout << "List 1 is empty" << endl;
    else cout << "List 1 is not empty" << endl;

    SLinkedList<int> list2;

    if(list2.empty()) cout << "List 2 is empty" << endl;
    else cout << "List 2 is not empty" << endl;

    cout<< list.indexOf(10) << endl;
    cout<< list2.indexOf(11) <<endl;

    if(list.contains(9)) cout << "Contained" << endl;
    else  cout << "Uncontained" << endl;
    return 0;
}