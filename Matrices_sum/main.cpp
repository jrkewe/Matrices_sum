//// The program operates on two matrices and prints results on the screen. It takes r and c 
//// as the dimensions of two matrices and then asks for values to fill them up.
//// Then we will be able to see a visual representation of both matrices and results.

#include <cstdio>
#include <cctype>
#include <iostream>
#include <vector>
#include "Matrix.h"
using namespace std;

//Overloading operator +
Matrix operator +(Matrix& A, Matrix& B) {
	Matrix R;
	int n = A.getDim().getRow();
	int m = A.getDim().getCol();
	R.setMtx(vector<vector<int>>(n, vector<int>(m)));
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
	int n = A.getDim().getRow();
	int m = A.getDim().getCol();
	R.setMtx(vector<vector<int>>(n, vector<int>(m)));
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
	int n = A.getDim().getRow();
	int m = A.getDim().getCol();
	R.setMtx(vector<vector<int>>(n, vector<int>(m)));
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
	int n = A.getDim().getRow();
	int m = A.getDim().getCol();
	R.setMtx(vector<vector<int>>(n, vector<int>(m)));
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
	int n = A.getDim().getRow();
	int m = A.getDim().getCol();
	R.setMtx(vector<vector<int>>(n, vector<int>(m)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(i, j) / x);
		}
	}
	return R;
}

//Transposition method
Matrix T(Matrix& A) {
	Matrix R;
	int n = A.getDim().getRow();
	int m = A.getDim().getCol();
	R.setMtx(vector<vector<int>>(A.getDim().getCol(), vector<int>(A.getDim().getRow())));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(j, i));
		}
	}
	return R;
}

//Printing method
void print(Matrix A) {
	for (int i = 0;i < A.getDim().getRow();i++) {
		for (int j = 0;j < A.getDim().getCol();j++) {
			cout << A.getElements(i, j) << " ";
		}
		cout << "\n";
	}
}

//Error checking loop
int insertInt(int& n) {
	while (true) {
		try {
			cin.exceptions(ios::failbit | ios::badbit);
			cin >> n;
			break;
		}
		catch (exception&) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			std::cout << "Try again: ";
		}
	}
	cout << "\n";
	return n;
}

//Exceptions handling
bool test(Dimensions A, Dimensions B) {
	try {
		if (A.getRow() != B.getRow()||A.getCol()!=B.getCol()) {
			throw std::domain_error("Matrices are not the same size.");
		}
	}
	catch (std::domain_error& e) {
		cout << "Domain error: " << e.what() << endl;
		return true;
	}
	return false;
}

int main() {

	int num;	//number

	//Dialog
	cout << "The program calculates matrices.\n\n";

	//Creating matrix A 
	cout << "Enter the size of matrix A: ";
	insertInt(num);
	Matrix A;
	A.setDim(num, num);
	A.setMtx(vector <vector<int>>(num, vector <int>(num, 0)));
	cout << "Enter the elements of matrix A:\n";
	for (int i = 0;i < A.getDim().getRow();i++) {
		for (int j = 0;j < A.getDim().getCol();j++) {
			int ele;
			insertInt(ele);
			A.setElements(i, j, ele);
		}
	}

	//Creating matrix B 
	cout << "Enter the size of matrix B: ";
	insertInt(num);
	Dimensions dob = {num, num};
	Matrix B(dob, vector<vector<int>>(num, vector<int>(num, 0)));
	cout << "Enter the elements of matrix B:\n";
	for (int i = 0;i < B.getDim().getRow();i++) {
		for (int j = 0;j < B.getDim().getCol();j++) {
			int ele;
			insertInt(ele);
			B.setElements(i, j, ele);
		}
	}

	//Creating matrix C
	Matrix C(B);

	//Printing
	//Matrix A
	cout << "\nPrint matrix A:\n";
	for (int i = 0;i < A.getDim().getRow();i++) {
		for (int j = 0;j < A.getDim().getCol();j++) {
			cout << A.getElements(i, j) << " ";
		}
		cout << "\n";
	}

	//Matrix B
	cout << "\nPrint matrix B:\n";
	for (int i = 0;i < B.getDim().getRow();i++) {
		for (int j = 0;j < B.getDim().getCol();j++) {
			cout << B.getElements(i, j) << " ";
		}
		cout << "\n";
	}

	//Matrix C
	cout << "\nPrint matrix C:\n";
	for (int i = 0;i < C.getDim().getRow();i++) {
		for (int j = 0;j < C.getDim().getCol();j++) {
			cout << C.getElements(i, j) << " ";
		}
		cout << "\n";
	}

		while (true) {
			//Dialog
			cout << "The program respectively allows to: (1)+ (2)- (3)* (4)/ (5)T (6)Update matrix A (7)Update matrix B (8)Quit\n"
				<< "Select an option: ";
			insertInt(num);
			switch (num) {

			case 1:
				//Error test
				if (test(A.getDim(), B.getDim())) {
					break;
				}

				//Operations
				C = (A + B);

				//Printing sum of two matrices
				cout << "Printing sum of two matrices:" << endl;
				print(C);
				break;

			case 2:
				//Error test
				if (test(A.getDim(), B.getDim())) {
					break;
				}
				//Dialog and inserting selector s
				cout << "How do you want to subtract the matrices: (1)a-b (2)b-a: " << endl;
				insertInt(num);

				//Operations
				if (num == 1) {
					C = A - B;
				}
				else {
					C = B - A;
				}

				//Printing difference of two matrices a-b or b-a
				cout << "Printing difference of two matrices:" << endl;
				print(C);
				break;

			case 3:
				//Dialog and inserting selector s
				cout << "How do you want to multiply the matrices: (1)a*b (2)b*a (3)a*C (4)b*C : " << endl;
				insertInt(num);

				//Error test
				if (num == 1 || num == 2) {
					if (test(A.getDim(), B.getDim())) {
						break;
					}
				}

				//Operations
				if (num == 1) {
					C = A * B;
				}
				else if (num == 2) {
					C = B * A;
				}
				else if (num == 3) {
					cout << "Enter the factor:";
					int ftr;
					insertInt(ftr);
					C.setDim(A.getDim().getRow(), A.getDim().getCol());
					C = A * ftr;
				}
				else if (num == 4) {
					cout << "Enter the factor:";
					int n;
					insertInt(n);
					C.setDim(B.getDim().getRow(), B.getDim().getCol());
					C = B * n;
				}

				//Printing product 
				cout << "Printing product:\n" << endl;
				print(C);
				break;

			case 4:
				//Dialog and inserting selector s
				cout << "Which matrix you want to devide: (1)a (2)b: " << endl;
				insertInt(num);
				cout << "Enter the divisor:";
				int div;
				insertInt(div);

				//Operations
				if (num == 1) {
					C.setDim(A.getDim().getRow(), A.getDim().getCol());
					C = A / div;
				}
				else {
					C.setDim(B.getDim().getRow(), B.getDim().getCol());
					C = B / div;
				}

				//Printing quotient of matrix
				cout << "Printing quotient:\n" << endl;
				print(C);
				break;

			case 5:
				//Dialog and inserting selector s
				cout << "Which matrix you want to transpose: (1)a (2)b: " << endl;
				insertInt(num);

				//Operations
				if (num == 1) {
					C.setDim(A.getDim().getRow(), A.getDim().getCol());
					C = T(A);
				}
				else {
					C.setDim(B.getDim().getRow(), B.getDim().getCol());
					C = T(B);
				}

				//Printing
				print(C);
				break;

			case 6:
				//Updating matrix A 
				cout << "Enter the size of matrix A: ";
				insertInt(num);
				A.setDim(num, num);
				A.setMtx(vector <vector<int>>(num, vector <int>(num, 0)));
				cout << "Enter the elements of matrix A:\n";
				for (int i = 0;i < A.getDim().getRow();i++) {
					for (int j = 0;j < A.getDim().getCol();j++) {
						int ele;
						insertInt(ele);
						A.setElements(i, j, ele);
					}
				}
				break;

			case 7:
				//Updating matrix B
				cout << "Enter the size of matrix B: ";
				insertInt(num);
				B.setDim(num, num);
				B.setMtx(vector <vector<int>>(num, vector <int>(num, 0)));
				cout << "Enter the elements of matrix B:\n";
				for (int i = 0;i < B.getDim().getRow();i++) {
					for (int j = 0;j < B.getDim().getCol();j++) {
						int ele;
						insertInt(ele);
						B.setElements(i, j, ele);
					}
				}
				break;

			case 8:
				cout << "Quit";
				return 0;

			default:
				;
			}
	}
	return 0;
}