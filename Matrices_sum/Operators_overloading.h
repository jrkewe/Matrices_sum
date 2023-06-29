#ifndef OPERATORSOVERLOADING
#define OPERATORSOVERLOADING

#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

//Overloading operator +
Matrix operator +(Matrix& A, Matrix& B);

//Overloading operator -
Matrix operator -(Matrix& A, Matrix& B);

//Overloading operator * 
Matrix operator *(Matrix& A, Matrix& B);

//Overloading operator * 
Matrix operator *(Matrix& A, int n);

//Overloading operator /
Matrix operator /(Matrix& A, int n);

#endif 
