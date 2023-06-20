//// The program operates on two matrices and prints results on the screen. It takes r and c 
//// as the dimensions of two matrices and then asks for values to fill them up.
//// Then we will be able to see a visual representation of both matrices and results.

#include <cstdio>
#include <cctype>
#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

//Parameterized constructor
Matrix::Matrix(int r, int c, std::vector<std::vector<int>> matrix) {
	this->r = r;
	this->c = c;
	this->matrix = matrix;
}
//Copy constructor
Matrix::Matrix(const Matrix& original):
	c(original.c),
	r(original.r),
	matrix(original.matrix) {
}
//Destructor
Matrix::~Matrix() {}

//Get/Set for r
int Matrix::getr() {
	return r;
}
void Matrix::setr(int x) {
	this->r = x;
}

//Get/Set for c
int Matrix::getc() {
	return c;
}
void Matrix::setc(int c) {
	this->c = c;
}

//Get/Set for matrix
vector<vector<int>> Matrix::getmtx() {
	return matrix;
}
void Matrix::setmtx(vector<vector<int>> mtx) {
	matrix = mtx;
}

//Get/Set for elements of matrix
int Matrix::getelements(int i, int j) {
	return matrix[i][j];
}
void Matrix::setelements(int i, int j, int x) {
	matrix[i][j] = x;
}

//Error checking loop
int InsertInt(int& n) {
	while (true) {
		try {
			cin.exceptions(ios::failbit | ios::badbit);
			cin >> n;
			break;
		}
		catch (exception&) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Try again: ";
		}
	}
	cout << "\n";
	return n;
}

//Overloading operator +
Matrix operator +(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getr();
	int m = A.getc();
	R.setmtx(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setelements(i, j, A.getelements(i, j) + B.getelements(i, j));
		}
	}
	return R;
}

//Overloading operator -
Matrix operator -(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getr();
	int m = A.getc();
	R.setmtx(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setelements(i, j, A.getelements(i, j) - B.getelements(i, j));
		}
	}
	return R;
}

//Overloading operator *
Matrix operator *(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getr();
	int m = A.getc();
	R.setmtx(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setelements(i, j, A.getelements(i, j) * B.getelements(i, j));
		}
	}
	return R;
}

//Overloading operator /
Matrix operator /(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getr();
	int m = A.getc();
	R.setmtx(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setelements(i, j, A.getelements(i, j) / B.getelements(i, j));
		}
	}
	return R;
}

int main() {
	
	int s;	//selector

	//Dialog
	cout << "The program calculates matrices.\n\n";

	//Creating matrix A 
	cout << "Enter the size of matrix A: ";
	InsertInt(s);
	Matrix A;
	A.setr(s);
	A.setc(s);
	A.setmtx ( vector <vector<int>> (s,vector <int>(s,0)));
	cout << "Enter the elements of matrix A:\n";
	for (int i = 0;i<A.getr();i++) {
		for (int j = 0;j<A.getc();j++) {
			InsertInt(s);
			A.setelements(i,j,s);
		}
	}

	//Creating matrix B 
	cout << "Enter the size of matrix B: ";
	InsertInt(s);
	Matrix B (s, s, vector<vector<int>> (s, vector<int>(s, 0)));
	cout << "Enter the elements of matrix B:\n";
	for (int i = 0;i < B.getr();i++) {
		for (int j = 0;j < B.getc();j++) {
			InsertInt(s);
			B.setelements(i, j, s);
		}
	}

	//Creating matrix C
	Matrix C(B);

	//Printing
	//Matrix A
	cout << "\nPrint matrix A:\n";
	for (int i = 0;i < A.getr();i++) {
		for (int j = 0;j < A.getc();j++) {
			cout << A.getelements(i, j) << " ";
		}
		cout << "\n";
	}

	//Matrix B
	cout << "\nPrint matrix B:\n";
	for (int i = 0;i < B.getr();i++) {
		for (int j = 0;j < B.getc();j++) {
			cout << B.getelements(i, j) << " ";
		}
		cout << "\n";
	}

	//Matrix C
	cout << "\nPrint matrix C:\n";
	for (int i = 0;i < C.getr();i++) {
		for (int j = 0;j < C.getc();j++) {
			cout << C.getelements(i, j) << " ";
		}
		cout << "\n";
	}

	//Dialog
	cout << "The program respectively allows to: (1) + (2) - (3) * (4) /\n"
		<< "Select an option: ";
	InsertInt(s);

	switch (s) {
	case 1:
		C = (A + B);
		//Printing sum of two matrices
		cout << "Printing sum of two matrices:" << endl;
		break;
	case 2:
		//Dialog and inserting selector s
		cout << "How do you want to subtract the matrices: (1)a-b (2)b-a: " << endl;
		InsertInt(s);

		//Printing difference of two matrices a-b or b-a
		if (s == 1) {
			C = A-B;
		}
		else {
			C = B-A;
		}
		cout << "Printing difference of two matrices:" << endl;
		break;
	case 3:
		C = A * B;
		//Printing product of two matrices
		cout << "Printing product of two matrices:" << endl;
		break;
	case 4:
		//Dialog and inserting selector s
		cout << "How do you want to devide the matrices: (1)a/b (2)b/a: " << endl;
		InsertInt(s);

		//Printing quotient of two matrices a/b or b/a
		if (s == 1) {
			C = A / B;
			cout << "Printing quotient of two matrices:" << endl;
		}
		else {
			C = B / A;
			cout << "Printing quotient of two matrices:" << endl;
		}
		break;
	default:;
	}
	//Printing the reasult
	for (int i = 0;i < C.getr();i++) {
		for (int j = 0;j < C.getc();j++) {
			cout << C.getelements(i, j) << " ";
		}
		cout << "\n";
	}
	return 0;
}