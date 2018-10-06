//Aaron Nicanor

//Header Files
#include "Polynomial.h"
#include "Node.h"

//Libraries
#include <iostream>
#include <utility>

using namespace std;

//constructor
template<class Type>
Polynomial<Type>::Polynomial()
{
        headPtr = nullptr;
}

//destructor
template<class Type>
Polynomial<Type>::~Polynomial()
{
        Node<Type>* ptr = headPtr;
        while (ptr != nullptr)
        {
                Node<Type>* temp;
                temp = ptr;
                ptr = ptr->getNext();
                delete temp;
        }
}

//inserts a new node into the list
template<class Type>
void Polynomial<Type>::insert(const Type& newEntry)
{
        Node<Type>* ptr = new Node<Type>(newEntry);
        ptr->setNext(headPtr);
        headPtr = ptr;
}

//evaluates the polynomial with the given x value. In this case, it will multiply the coefficent
//and the given x value to the power of whatever it's at in the node. Then it will add them all up
//and print the result
template<class Type>
void Polynomial<Type>::evaluate(int xValue)
{
        Node<Type>* ptr = headPtr;
        unsigned polyResult = 0;

        //goes through the entire list and calculates the polyResult
        while (ptr != nullptr)
        {
                unsigned powResult = 1;

                //evaluates the power
                for (unsigned i = 0; i < ptr->getItem().second; i++)
                {
                        powResult *= xValue;
                }
                polyResult += ptr->getItem().first * powResult;
                ptr = ptr->getNext();
        }

        cout<< polyResult << " ";
}
