//// The program operates on two matrices and prints results on the screen. It takes r and c 
//// as the dimensions of two matrices and then asks for values to fill them up.
//// Then we will be able to see a visual representation of both matrices and results.

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Tests.h"
#include "Operators_overloading.h"
using namespace std;

int main() {

	//Dialog
	cout << "The program allows to: add, subtract, multiply, divide, transpose matrices.\n\n";

	int number;

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

	cout << "Size of matrix B: ";
	testInt(number);
	Dimensions dob = {number, number};
	Matrix B(dob, vector<vector<int>>(number, vector<int>(number, 0)));
	cout << "Enter the elements of matrix B:\n";
	for (int i = 0;i < B.getDimentions().getNumberOfRows();i++) {
		for (int j = 0;j < B.getDimentions().getNumberOfColumns();j++) {
			int element;
			testInt(element);
			B.setElements(i, j, element);
		}
	}

	Matrix C(B);

	//Menu
	while (true) {
		cout << "The program respectively allows to: (1)+ (2)- (3)* (4)/ (5)T (6)Update matrix A (7)Update matrix B (8)Quit\n"
		<< "Select an option: ";
		testInt(number);

		switch (number) {

			case 1:
				//Error testMatricesSize
				if (testMatricesSize(A.getDimentions(), B.getDimentions())) {
					break;
				}

				//Operations
				C = (A + B);

				//Print
				cout << "Printing sum of two matrices:" << endl;
				C.print();
				break;

			case 2:
				//Error testMatricesSize
				if (testMatricesSize(A.getDimentions(), B.getDimentions())) {
					break;
				}

				//Dialog
				cout << "How do you want to subtract the matrices: (1)a-b (2)b-a: " << endl;
				testInt(number);

				//Operations
				if (number == 1) {
					C = A - B;
				}
				else {
					C = B - A;
				}

				//Print
				cout << "Printing difference of two matrices:" << endl;
				C.print();
				break;

			case 3:
				//Dialog
				cout << "How do you want to multiply the matrices: (1)a*b (2)b*a (3)a*C (4)b*C : " << endl;
				testInt(number);

				//Error testMatricesSize
				if (number == 1 || number == 2) {
					if (testMatricesSize(A.getDimentions(), B.getDimentions())) {
						break;
					}
				}

				//Operations
				if (number == 1) {
					C = A * B;
				}
				else if (number == 2) {
					C = B * A;
				}
				else if (number == 3 || number == 4) {
					cout << "Enter the factor:";
					int factor;
					testInt(factor);

					if (number == 3) {
						C.setDimentions(A.getDimentions().getNumberOfRows(), A.getDimentions().getNumberOfColumns());
						C = A * factor;
					}
					else if (number == 4) {
						C.setDimentions(B.getDimentions().getNumberOfRows(), B.getDimentions().getNumberOfColumns());
						C = B * factor;
					}
				}

				//Print
				cout << "Printing product:\n" << endl;
				C.print();
				break;

			case 4:
				//Dialog 
				cout << "Which matrix you want to devide: (1)a (2)b: " << endl;
				testInt(number);

				cout << "Enter the divisor:";
				int divisor;
				testInt(divisor);

				//Operations
				if (number == 1) {
					C.setDimentions(A.getDimentions().getNumberOfRows(), A.getDimentions().getNumberOfColumns());
					C = A / divisor;
				}
				else {
					C.setDimentions(B.getDimentions().getNumberOfRows(), B.getDimentions().getNumberOfColumns());
					C = B / divisor;
				}

				//Print
				cout << "Printing quotient:\n" << endl;
				C.print();
				break;

			case 5:
				//Dialog 
				cout << "Which matrix you want to transpose: (1)a (2)b: " << endl;
				testInt(number);

				//Operations
				if (number == 1) {
					C.setDimentions(A.getDimentions().getNumberOfRows(), A.getDimentions().getNumberOfColumns());
					C.T(A);
				}
				else if (number==2) {
					C.setDimentions(B.getDimentions().getNumberOfRows(), B.getDimentions().getNumberOfColumns());
					C.T(B);
				}

				//Print
				C.print();
				break;

			case 6:
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
				break;

			case 7:
				cout << "Size of matrix B: ";
				testInt(number);
				B.setDimentions(number, number);
				B.setMatrix(vector <vector<int>>(number, vector <int>(number, 0)));
				cout << "Elements of matrix B:\n";
				for (int i = 0;i < B.getDimentions().getNumberOfRows();i++) {
					for (int j = 0;j < B.getDimentions().getNumberOfColumns();j++) {
						int element;
						testInt(element);
						B.setElements(i, j, element);
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