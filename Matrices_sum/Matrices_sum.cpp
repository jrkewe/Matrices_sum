//// The program adds to matrices and writes their sum on the screen. It takes n 
//// as the dimensions of two matrices and then asks for values to fill them up.
//// Then we will be able to see a visual representation of both matrices and their 
//// sum on the screen.

#include <cstdio>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
	int r = 0;		//rows
	int c = 0;		//columns
	vector<vector<int>> matrix;

public:

	//Default constructor
	Matrix() {
		r = 0;
		c = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0;j < c;j++) {
				matrix[i][j] = 0;
			}
		}
	}
	//Parameterized constructor
	Matrix(int r, int c, vector<vector<int>> matrix) {
		this->r = r;
		this->c = c;
		this->matrix = matrix;
	}
	//Copy constructor
	Matrix(const Matrix& original) :
		c(original.c),
		r(original.r),
		matrix(original.matrix) {
	}
	//Destructor
	~Matrix() {}

	//Get/Set for r
	int getr() {
		return r;
	}
	void setr(int x) {
		this->r = x;
	}

	//Get/Set for c
	int getc() {
		return c;
	}
	void setc(int c) {
		this->c = c;
	}

	//Get/Set for matrix
	vector<vector<int>> getmtx() {
		return matrix;
	}
	void setmtx(vector<vector<int>> mtx) {
		matrix = mtx;
	}

	//Get/Set for elements of matrix
	int getelements(int i, int j) {
		return matrix[i][j];
	}
	void setelements(int i, int j, int x) {
		matrix[i][j] = x;
	}
};

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
		//Printing sum of two matrices
		cout << "Printing sum of two matrices:" << endl;
		for (int i = 0;i<A.getr();i++) {
			for (int j = 0;j < A.getc();j++) {
				cout << A.getelements(i, j) + B.getelements(i, j) << " ";
			}
			cout << "\n";
		}
		break;
	case 2:
		//Dialog and inserting selector s
		cout << "How do you want to subtract the matrices: (1)a-b (2)b-a: " << endl;
		InsertInt(s);

		//Printing difference of two matrices a-b or b-a
		if (s == 1) {
			cout << "Printing difference of two matrices:" << endl;
			for (int i = 0;i < A.getr();i++) {
				for (int j = 0;j < A.getc();j++) {
					cout << A.getelements(i, j) - B.getelements(i, j) << " ";
				}
				cout << "\n";
			}
			break;
		}
		else {
			cout << "Printing difference of two matrices:" << endl;
			for (int i = 0;i < A.getr();i++) {
				for (int j = 0;j < A.getc();j++) {
					cout << B.getelements(i, j) - A.getelements(i, j) << " ";
				}
				cout << "\n";
			}
			break;
		}

		break;
	case 3:
		//Printing product of two matrices
		cout << "Printing product of two matrices:" << endl;
		for (int i = 0;i < A.getr();i++) {
			for (int j = 0;j < A.getc();j++) {
				cout << A.getelements(i, j) * B.getelements(i, j) << " ";
			}
			cout << "\n";
		}
		break;
	case 4:
		//Dialog and inserting selector s
		cout << "How do you want to devide the matrices: (1)a/b (2)b/a: " << endl;
		InsertInt(s);

		//Printing quotient of two matrices a/b or b/a
		if (s == 1) {
			cout << "Printing quotient of two matrices:" << endl;
			for (int i = 0;i < A.getr();i++) {
				for (int j = 0;j < A.getc();j++) {
					cout << A.getelements(i, j) / B.getelements(i, j) << " ";
				}
				cout << "\n";
			}
		}
		else {
			cout << "Printing quotient of two matrices:" << endl;
			for (int i = 0;i < A.getr();i++) {
				for (int j = 0;j < A.getc();j++) {
					cout << B.getelements(i, j) / A.getelements(i, j) << " ";
				}
				cout << "\n";
			}
		}
		break;
	default:;
	}
	return 0;
}