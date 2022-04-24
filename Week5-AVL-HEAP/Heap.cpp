#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    void clear();
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();

    int getItem(T item);
    void remove(T item);
    void clear();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};


//Your code goes here
template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return !count;
}

template<class T>
T Heap<T>::peek(){
    if (isEmpty()) return -1;
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    if (isEmpty()) return false;
    for (int i = 0; i < count; ++i) {
        if (elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (isEmpty()) return false;
    elements[0] = elements[count - 1];
    count--;
    reheapDown(0);
    return true;
}
////////////////////////////////////////
template<class T>
void Heap<T>::push(T item){
    if (count == capacity){
        ensureCapacity(this->capacity * 2);
    }
    elements[count] = item;
    count++;
    reheapUp(count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T* newElements = new T[minCapacity];
    for (int i = 0; i < count; ++i) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = minCapacity;
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position <= 0 || position >= count) return;
    int parent = (position - 1) / 2;
    if (elements[parent] < elements[position]){
        int temp = elements[parent];
        elements[parent] = elements[position];
        elements[position] = temp;
        reheapUp(parent);
    }
    return;
}
////////////////////////////////////////
template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    if (!count) return -1;
    for (int i = 0; i < count; ++i) {
        if (elements[i] == item) return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if (index == -1) return;
    else {
        elements[index] = elements[count - 1];
        count--;
        reheapDown(index);
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    delete[] elements;
    elements = NULL;
    count = 0;
}
