#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

//Overloading operator +
Matrix operator +(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getDimentions().getNumberOfRows();
	int m = A.getDimentions().getNumberOfColumns();
	R.setMatrix(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(i, j) + B.getElements(i, j));
		}
	}
	return R;
}

//Overloading operator -
Matrix operator -(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getDimentions().getNumberOfRows();
	int m = A.getDimentions().getNumberOfColumns();
	R.setMatrix(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(i, j) - B.getElements(i, j));
		}
	}
	return R;
}

//Overloading operator * //for two matrices
Matrix operator *(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getDimentions().getNumberOfRows();
	int m = A.getDimentions().getNumberOfColumns();
	R.setMatrix(vector<vector<int>>(n, vector<int>(m)));
	//i i j to wspolrzedne elementu macierzy R
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			//Liczenie jednej wspolrzednej w macierzy wynikowej
			int x = 0;
			for (int k = 0;k < n;k++) {
				x += (A.getElements(i, k) * B.getElements(k, j));
			}
			R.setElements(i, j, x);
		}
	}
	return R;
}

//Overloading operator * //for matrix and const number
Matrix operator *(Matrix& A, int x) {
	Matrix R;
	int n = A.getDimentions().getNumberOfRows();
	int m = A.getDimentions().getNumberOfColumns();
	R.setMatrix(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(i, j) * x);
		}
	}
	return R;
}

//Overloading operator /
Matrix operator /(Matrix& A, int x) {
	Matrix R;
	int n = A.getDimentions().getNumberOfRows();
	int m = A.getDimentions().getNumberOfColumns();
	R.setMatrix(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(i, j) / x);
		}
	}
	return R;
}