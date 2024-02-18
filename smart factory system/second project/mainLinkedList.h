#ifndef MAINLINKEDLIST_H
#define MAINLINKEDLIST_H

#include "Stack.h"
#include "SubLinkedList.h"
#include <iostream>
#include <string>
using namespace std;
class mainLinkedList
{
private:
    Stack<string>* steps;
    SubLinkedList<Stack<string>> products;

public:
    mainLinkedList();
    void add_steps();
    void add_product();
    void release_product();
    void view_steps_to_the_top_product();
    void print_products();
    void view_current_step();
    void reverselist();
    void total();
};

mainLinkedList::mainLinkedList() :steps(nullptr) {}

void mainLinkedList::add_steps()
{
    if (steps == nullptr)
    {
        steps = new Stack<string>;
    }
    cout << "[*] "
         << "\033[33mAdd the step \033[0m"<<"[max: 5]: ";
    string step;
    cin.ignore();
    getline(cin, step);
    steps->push(step);
}

void mainLinkedList::add_product()
{
    if (steps == NULL)
    {
        cout <<"[*] "
             << "There are no steps defined for this product." << endl << endl;
        return;
    }
    else
    {
        products.enqueue(*steps);
        steps = nullptr;
        cout << "[*] "
             << "\033[33mPROJECT SAVED  \033[0m"<<endl<<endl;
    }
}
void mainLinkedList::view_current_step()
{
    if (steps == nullptr)
    {
        cout <<"[*] "
             << "No Steps were entered."<<endl<<endl;
        return;
    }
    cout <<"[*] "
         << "Product Steps: " << endl << endl;
    steps->print();
}
void mainLinkedList::release_product()
{
    if (!products.isempty())
    {
        cout <<"[*] "
             << "Released Product Steps: " << endl << endl;
        products.dequeue().print();
    }
    else
    {
        cout <<"[*] "
             << "No products in the Smart Factory." << endl;
    }
}

void mainLinkedList::view_steps_to_the_top_product()
{
    if (!products.isempty())
    {
        cout <<"[*] "
             << "Viewing steps for the top product: " << endl<<endl;
        products.peekTop().print();
    }
    else
    {
        cout <<"[*] "
             << "No products in the SmartFactory." << endl;
    }
}

void mainLinkedList::print_products()
{
    if (!products.isempty()) {
        cout << "[*] "
             <<"Product List: " << endl << endl;
        products.print();
    }
    else
    {
        cout <<"[*] "
             << "No Products Available" << endl << endl;
    }
}

void mainLinkedList::reverselist()
{
    if (!products.isempty())
    {
        products.Reverse();
        cout << "[*] "
             << "Order Reveresed Successfully" << endl << endl;
    }
    else
    {
        cout << "[*] "
            << "No Products Available" << endl << endl;
    }
}

void mainLinkedList::total()
{
    cout << "Total Products: " << products.getTotalElements() << endl; ;
}

#endif 
