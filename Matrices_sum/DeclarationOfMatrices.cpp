#include <iostream>
#include "Matrix.h"
#include "Tests.h"
#include "Texte.h"

using namespace std;

int number;

void declarationOfMatrixA(Matrix& A) {
	texteMatrixA(0);
	testInt(number);
	A.setDimentions(number, number);
	A.setMatrix(vector <vector<int>>(number, vector <int>(number, 0)));
	texteMatrixA(1);
	for (int i = 0;i < A.getDimentions().getNumberOfRows();i++) {
		for (int j = 0;j < A.getDimentions().getNumberOfColumns();j++) {
			int element;
			testInt(element);
			A.setElements(i, j, element);
		}
	}
}

void declarationOfMatrixB(Matrix& B) {
	texteMatrixB(0);
	testInt(number);
	B.setDimentions(number, number);
	B.setMatrix(vector <vector<int>>(number, vector <int>(number, 0)));
	texteMatrixB(1);
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