// The program adds to matrices and writes their sum on the screen. It takes n 
// as the dimensions of two matrices and then asks for values to fill them up.
// Then we will be able to see a visual representation of both matrices and their 
// sum on the screen.

#include <cstdio>
#include <cctype>
#include <iostream>
#include "Declarations.h"
using namespace std;

int main() {

	//Variables:
	int n;					//matrices dimensions
	int a[dim][dim];		//matrix a;
	int b[dim][dim];		//matrix b;

	//Dialog
	cout << "The program adds two matrices of size n\n\n"
		<< "Enter the size of matrices : ";

	//Inserting size n
	InsertInt(n);

	//Inserting - elements of matrix a and b
	cout << "Inserting elements of matrix:" << endl;
	InsertValue(n, a);
	cout << "Inserting elements of matrix:" << endl;
	InsertValue(n, b);

	//Printing matrix a and b
	cout << "Printing matrix:" << endl;
	PrintMatrix(n, a);
	cout << "Printing matrix:" << endl;
	PrintMatrix(n, b);

	//Dialog
	cout << "The program respectively allows to: (1) + (2) - (3) * (4) /\n"
		<< "Select an option: ";

	//Inserting selector s
	int s;
	InsertInt(s);
	
	switch (s) {
	case 1:
		//Printing sum of two matrices
		cout << "Printing sum of two matrices:" << endl;
		SumOfTwoMatrices(n, a, b);
		break;
	case 2:
		//Dialog and inserting selector s
		cout << "How do you want to subtract the matrices: (1)a-b (2)b-a: " << endl;
		InsertInt(s);

		//Printing difference of two matrices a-b or b-a
		if (s == 1) {
			cout << "Printing difference of two matrices:" << endl;
			DifferenceOfTwoMatrices(n, a, b);
		}
		else {
			cout << "Printing difference of two matrices:" << endl;
			DifferenceOfTwoMatrices(n, b, a);
		}
		
		break;
	case 3:
		//Printing product of two matrices
		cout << "Printing product of two matrices:" << endl;
		ProductOfTwoMatrices(n, a, b);
		break;
	case 4:
		//Dialog and inserting selector s
		cout << "How do you want to devide the matrices: (1)a/b (2)b/a: " << endl;
		InsertInt(s);

		//Printing quotient of two matrices a/b or b/a
		if (s == 1) {
			cout << "Printing quotient of two matrices:" << endl;
			QuotientOfTwoMatrices(n, a, b);
		}
		else {
			cout << "Printing quotient of two matrices:" << endl;
			QuotientOfTwoMatrices(n, b, a);
		}
		break;
	default: ;
	}
	return 0;
}