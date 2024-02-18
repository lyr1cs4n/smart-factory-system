#ifndef SMARTFACTORY_H
#define SMARTFACTORY_H
#include "mainLinkedList.h"
template <typename T>
class SmartFactory
{
private:
    mainLinkedList mainList;
public:
    SmartFactory();
    void productSequenceManagement();
    void operationInformationStorage();
    void operationInformationRelease();
    void operationInformationProductStep();
    void operationInformationProduct();
    void OrderManagement();
    void operationViewCurrStep();
    void TotalProduct();
};

template <typename T>
SmartFactory<T>::SmartFactory() {
}
template <typename T>
void SmartFactory<T>::productSequenceManagement() {
    mainList.add_steps();
}
template <typename T>
void SmartFactory<T>::operationInformationStorage()
{
    mainList.add_product();
}
template <typename T>
void SmartFactory<T>::operationInformationRelease()
{
    mainList.release_product();
}
template <typename T>
void SmartFactory<T>::operationInformationProductStep()
{
    mainList.view_steps_to_the_top_product();
}
template <typename T>
void SmartFactory<T>::operationInformationProduct()
{
    mainList.print_products();
}
template <typename T>
void SmartFactory<T>::operationViewCurrStep()
{
    mainList.view_current_step();
}
template <typename T>
void SmartFactory<T>::OrderManagement()
{
    mainList.reverselist();
}
template <typename T>
void SmartFactory<T>::TotalProduct()
{
    mainList.total();
}

#endif // SMARTFACTORY_H
