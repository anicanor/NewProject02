//Aaron Nicanor
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Node.h"
#include <utility>

using namespace std;
template<class Type>

class Polynomial
{
        private:
            Node<Type>* headPtr;

        public:
            Polynomial();
            ~Polynomial();
            void insert(const Type& newEntry);
            void evaluate(int);
};
#include"Polynomial.cpp"
#endif
