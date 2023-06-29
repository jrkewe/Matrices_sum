#include <iostream>
#include "Dimensions.h"
#include "Matrix.h"
using namespace std;

//Constructors
Matrix::Matrix(Dimensions dimentionsobject, std::vector<std::vector<int>> matrix) : dimentionsObject(dimentionsobject), matrix(matrix) {}
Matrix::Matrix(const Matrix& original) : dimentionsObject(original.dimentionsObject), matrix(original.matrix) {}
Matrix::~Matrix() {}

//Get/Set - dimentions object
Dimensions Matrix::getDimentions() {
	return dimentionsObject;
}
void Matrix::setDimentions(int r, int c) {
	dimentionsObject = {r,c};
}

//Get/Set - matrix
vector<vector<int>> Matrix::getMatrix() {
	return matrix;
}
void Matrix::setMatrix(vector<vector<int>> Matrix) {
	matrix = Matrix;
}

//Get/Set - elements
int Matrix::getElements(int i, int j) {
	return matrix[i][j];
}
void Matrix::setElements(int i, int j, int x) {
	matrix[i][j] = x;
}

//Print method
void Matrix::print() {
	for (int i = 0;i < dimentionsObject.getNumberOfRows();i++) {
		for (int j = 0;j < dimentionsObject.getNumberOfColumns();j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

//Transposition method
Matrix Matrix::T(Matrix& A) {
	Matrix R;
	int n = A.getDimentions().getNumberOfRows();
	int m = A.getDimentions().getNumberOfColumns();
	R.setMatrix(vector<vector<int>>(m, vector<int>(n)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(j, i));
		}
	}
	return R;
}