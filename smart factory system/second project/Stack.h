#ifndef STACK_H
#define STACK_H
#include "Stack.h"
#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    int Capacity;
    T* array;
    int top;
public:
    Stack();
    void push(T val);
    void pop();
    T peek() const;
    bool  isEmpty() ;
    void print() ;
};

template <typename T>
Stack<T>::Stack() : top(-1)
{
    Capacity = 5;
    array = new T[Capacity];
}

template <typename T>
void Stack<T>::push(T val)
{
    if (top < Capacity - 1)
    {
        array[++top] = val;
    }
    else
    {
        std::cout << "Stack overflow" << std::endl;
    }
}

template <typename T>
void Stack<T>::pop()
{
    if (top >= 0)
    {
        --top;
    }
    else
    {
        std::cout << "Stack underflow" << std::endl;
    }
}

template <typename T>
T Stack<T>::peek() const
{
    if (top >= 0)
    {
        return array[top];
    }
    return T();
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;
}

template <typename T>
void Stack<T>::print() 
{
    if (isEmpty())
    {
        cout << "Stack is Empty." << endl;
    }
    else
    {
        for (int i = top; i >= 0; --i)
        {
            cout << "[*] "
                << "\033[33mStep \033[0m" << i+1 <<"\033[33m: \033[0m" << array[i] << endl;
        }
        cout << endl;
    }
}

#endif // STACK_H
