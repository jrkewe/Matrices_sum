#include <iostream>
#include "Matrix.h"
#include "Tests.h"

using namespace std;

int number;

void declarationOfMatrixA(Matrix& A) {
	Matrix A;
	cout << "Size of matrix A: ";
	testInt(number);
	A.setDimentions(number, number);
	A.setMatrix(vector <vector<int>>(number, vector <int>(number, 0)));
	cout << "Elements of matrix A:\n";
	for (int i = 0;i < A.getDimentions().getNumberOfRows();i++) {
		for (int j = 0;j < A.getDimentions().getNumberOfColumns();j++) {
			int element;
			testInt(element);
			A.setElements(i, j, element);
		}
	}
}

void declarationOfMatrixB(Matrix& B) {
	cout << "Size of matrix B: ";
	testInt(number);
	Dimensions dob = { number, number };
	Matrix B(dob, vector<vector<int>>(number, vector<int>(number, 0)));
	cout << "Enter the elements of matrix B:\n";
	for (int i = 0;i < B.getDimentions().getNumberOfRows();i++) {
		for (int j = 0;j < B.getDimentions().getNumberOfColumns();j++) {
			int element;
			testInt(element);
			B.setElements(i, j, element);
		}
	}
}

void declarationOfMatrixC(Matrix& B) {
	Matrix C(B);
}