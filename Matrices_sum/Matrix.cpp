#include <iostream>
#include "Dimensions.h"
#include "Matrix.h"
using namespace std;

//Member initializer list
Matrix::Matrix(Dimensions DIMOBJ, std::vector<std::vector<int>> mtx):dimobj(DIMOBJ), matrix(mtx) {}

//Copy constructor
Matrix::Matrix(const Matrix& original):
	dimobj(original.dimobj),
	matrix(original.matrix) {
}
//Destructor
Matrix::~Matrix() {}

//Get/Set for obj dimensions
Dimensions Matrix::getDim() {
	return dimobj;
}
void Matrix::setDim(int r, int c) {
	this->dimobj = {r,c};
}

//Get/Set for matrix
vector<vector<int>> Matrix::getMtx() {
	return matrix;
}
void Matrix::setMtx(vector<vector<int>> mtx) {
	matrix = mtx;
}

//Get/Set for elements of matrix
int Matrix::getElements(int i, int j) {
	return matrix[i][j];
}
void Matrix::setElements(int i, int j, int x) {
	matrix[i][j] = x;
}
