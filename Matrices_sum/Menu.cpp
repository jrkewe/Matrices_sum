#include <iostream>
#include <deque>
#include "Dimensions.h"
#include "Matrix.h"
#include "Tests.h"
#include "OperatorsOverloading.h"
#include "Menu.h"
#include "Texte.h"
using namespace std;

int Menu(Matrix& A, Matrix& B, Matrix& C, Matrix& D) {
	int number;

	//Menu
	while (true) {
		texteSwitch();
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
			texteAddition();
			C.print();
			break;

		case 2:
			//Error testMatricesSize
			if (testMatricesSize(A.getDimentions(), B.getDimentions())) {
				break;
			}

			//Dialog
			texteSubstraction(0);
			testInt(number);

			//Operations
			if (number == 1) {
				C = A - B;
			}
			else {
				C = B - A;
			}

			//Print
			texteSubstraction(1);
			C.print();
			break;

		case 3:
			//Dialog
			texteMultiplication(0);
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
				texteMultiplication(1);
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
			texteMultiplication(2);
			C.print();
			break;

		case 4:
			//Dialog 
			texteDivision(0);
			testInt(number);

			texteDivision(1);
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
			texteDivision(2);
			C.print();
			break;

		case 5:
			//Dialog 
			texteTransposition();
			testInt(number);

			//Operations
			if (number == 1) {
				C.setDimentions(A.getDimentions().getNumberOfRows(), A.getDimentions().getNumberOfColumns());
				C.T(A);
			}
			else if (number == 2) {
				C.setDimentions(B.getDimentions().getNumberOfRows(), B.getDimentions().getNumberOfColumns());
				C.T(B);
			}

			//Print
			C.print();
			break;

		case 6:
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
			break;

		case 7:
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
			break;

		case 8:
		{
			//Dialog 
			cout << "Eigenvalue of witch matrix do you want to count: (1)A (2)B: " << endl;
			testInt(number);


			int sum;
			sum = -1;
			int product;
			deque <int> dq;

			//Operations
			if (number == 1) {
				D.setMatrix(vector<vector<int>>(A.getDimentions().getNumberOfColumns(), vector<int>(A.getDimentions().getNumberOfRows())));
				//TODO:
				for (int i = 0;i < D.getDimentions().getNumberOfRows();i++) {
					dq.push_back(i);
					for (int j = 0;j < D.getDimentions().getNumberOfColumns();j++) {
						D.setElements(i, j, A.getElements(i, j));
					}
				}
				for (int j = 0;j < D.getDimentions().getNumberOfRows();j++) {
					product = 1;
					for (int i = 0;i < D.getDimentions().getNumberOfRows();i++) {
						product *= D.getElements(i, dq[i]);
						int x = dq[0];
						dq.pop_front();
						dq.push_back(x);
					}
					sum += product;
				}
				cout << "sum" << sum << endl;
				//TODO
			}
			else if (number == 2) {
				D.setMatrix(vector<vector<int>>(B.getDimentions().getNumberOfColumns(), vector<int>(A.getDimentions().getNumberOfRows())));
				for (int i = 0;i < B.getDimentions().getNumberOfRows();i++) {
					for (int j = 0;j < B.getDimentions().getNumberOfColumns();j++) {
						if (i == j) {
							cout << "v" << endl;
						}
						else {
							D.setElements(i, j, B.getElements(i, j));
						}
					}
				}
			}//for Matrix B

			//Print
			D.print();

			break;
		}
		case 9:
			texteQuit();
			return 0;

		default:
			;
		}

	}
}