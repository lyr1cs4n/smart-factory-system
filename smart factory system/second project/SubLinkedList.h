#ifndef SUBLINKEDLIST_H
#define SUBLINKEDLIST_H
#include<iostream>
#include <algorithm>
#include <iterator>
using namespace std;
template <typename T>
class SubLinkedList
{
private:
    template <typename U>
    struct Node
    {
        U* data;
        Node<U>* next;
        size_t ArraySize;
        size_t index;
        size_t ArrayCap;
        Node()
        {
            index = 0;
            ArraySize = 0;
            ArrayCap = 5;
            next = nullptr;
            data = new U[ArrayCap];
        }
        ~Node()
        {
            delete[] data;
        }

        bool isfull()
        {
            return ArraySize == ArrayCap;
        }
    };
    Node<T>* front;
    Node<T>* rear;
    size_t ListSize;
    size_t TotalElements;
public:
    SubLinkedList();
    virtual ~SubLinkedList();
    void enqueue(const T& data);
    T dequeue();
    void print();
    T peekTop();
    bool isempty();
    int getTotalElements();
    void Reverse();

};

template <typename T>
SubLinkedList<T>::SubLinkedList() :front(nullptr), rear(nullptr), ListSize(0), TotalElements(0) {}
template <typename T>
SubLinkedList<T>::~SubLinkedList()
{
    while (!isempty())
    {
        dequeue();
    }
}
template <typename T>
void SubLinkedList<T>::enqueue(const T& data)
{
    if (isempty())
    {
        front = rear = new Node<T>;
        ListSize++;
    }
    else if (front->isfull())
    {
        Node<T>* temp = new Node<T>;
        rear->next = temp;
        rear = temp;
        ListSize++;
    }
    rear->data[rear->ArraySize++] = data;
    TotalElements++;
}
template <typename T>
T SubLinkedList<T>::dequeue()
{
    if (isempty())
    {
        cout << "empty" << endl;
        return T();  
    }

    T dequeuedElement = front->data[front->index++];

    if (front->index > front->ArraySize - 1)
    {
        Node<T>* temp = front;
        front = front->next;
        delete temp;
        ListSize--;
    }
    TotalElements--;
    return dequeuedElement;
}

template <typename T>
void SubLinkedList<T>::print()
{
    int count = TotalElements;
    Node<T>* ptr = front;

    while (ptr != nullptr)
    {
        for (int i = ptr->index; i < ptr->ArraySize; i++)
        {
            cout << "Product " << TotalElements - count << " :" << endl << endl;
            ptr->data[i].print();
            count--;
        }
        ptr = ptr->next;
    }
}
template <typename T>
T SubLinkedList<T>::peekTop()
{
    if (!isempty() && front->index < front->ArraySize)
    {
        return front->data[front->index];
    }
    return T();
}
template <typename T>
bool SubLinkedList<T>::isempty()
{
    return ListSize == 0;
}
template <typename T>
int SubLinkedList<T>::getTotalElements()
{
    return TotalElements;
}
template <typename T>
void SubLinkedList<T>::Reverse()
{
    Node<T>* prev = nullptr;
    Node<T>* current = front;
    Node<T>* next = nullptr;

    while (current != nullptr && current->ArraySize > 0)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    rear = front;
    front = prev;

    Node<T>* ptr = front;
    while (ptr != nullptr)
    {
        int start = ptr->index;
        int end = ptr->ArraySize - 1;

        while (start < end)
        {
            T temp = ptr->data[start];
            ptr->data[start] = ptr->data[end];
            ptr->data[end] = temp;

            start++;
            end--;
        }

        ptr = ptr->next;
    }
}

#endif // SUBLINKEDLIST_H
