//// The program operates on two matrices and prints results on the screen. It takes r and c 
//// as the dimensions of two matrices and then asks for values to fill them up.
//// Then we will be able to see a visual representation of both matrices and results.

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Tests.h"
#include "OperatorsOverloading.h"
#include "Menu.h"
#include "MatrixDeclaration.h"
using namespace std;

int main() {

	//Dialog
	cout << "The program allows to: add, subtract, multiply, divide, transpose matrices.\n\n";

	Matrix A, B, C;

	declarationOfMatrixA(A);
	declarationOfMatrixB(B);
	declarationOfMatrixC(B);

	Menu(A, B, C);

	return 0;
}