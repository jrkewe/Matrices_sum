// The program adds to matrices and writes their sum on the screen. It takes n 
// as the dimensions of two matrices and then asks for values to fill them up.
// Then we will be able to see a visual representation of both matrices and their 
// sum on the screen.

#include <cstdio>
#include <cctype>
#include <iostream>
using namespace std;
#define max 20


void InsertValue(int n, int a[max][max]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << "[" << i << "][" << j << "]: ";
			while(scanf_s("%d", &a[i][j]) != 1|| getchar() != '\n') {
				cout << "The data was incorrect. Try again: " << endl;
				while (getchar() != '\n')
					;
			}
		}
	}
	cout << "\n";
}

void PrintMatrix(int n,int a[max][max]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void SumOfTwoMatrices(int n, int a[max][max], int b[max][max]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] + b[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << endl;
}

void DifferenceOfTwoMatrices(int n, int a[max][max], int b[max][max]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] - b[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << endl;
}

void ProductOfTwoMatrices(int n, int a[max][max], int b[max][max]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] * b[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << endl;
}

void QuotientOfTwoMatrices(int n, int a[max][max], int b[max][max]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			//error if b[i][j]=0
			if (b[i][j] == 0) {
				break;
			}
			cout << (a[i][j] / b[i][j]) << " ";
		}
		cout << "\n";

	}
	cout << "\n" << endl;
}

int main() {

	//Variables:
	int n;					//matrices dimensions
	int a[max][max];		//matrix a;
	int b[max][max];		//matrix b;

	//Dialog
	cout << "The program adds two matrices of size n\n\n"
		<< "Enter the size of matrices : ";

	//Inserting size n
	while (scanf_s("%d", &n) != 1 || n < 0 || getchar() != '\n') {
		cout << "The data was incorrect. Try again: " << endl;
		while (getchar() != '\n')
			;
	}

	//Inserting - elements of matrix a
	cout << "Inserting elements of matrix:" << endl;
	InsertValue(n, a);

	//Inserting - elements of matrix b
	cout << "Inserting elements of matrix:" << endl;
	InsertValue(n, b);

	//Printing matrix a
	cout << "Printing matrix:" << endl;
	PrintMatrix(n, a);

	//Printing matrix b
	cout << "Printing matrix:" << endl;
	PrintMatrix(n, b);

	//Dialog
	cout << "The program allows respectively to: (1) + (2) - (3) * (4) /\n"
		<< "Select an option: ";
	int s;
	//Inserting selector s
	while (scanf_s("%d", &s) != 1 || s < 1 || s > 4 || getchar() != '\n') {
		cout << "The data was incorrect. Try again: " << endl;
		while (getchar() != '\n')
			;
	}
	
	switch (s) {
	case 1:
		//Printing sum of two matrices
		cout << "Printing sum of two matrices:" << endl;
		SumOfTwoMatrices(n, a, b);
		break;
	case 2:
		//Dialog
		cout << "How do you want to subtract the matrices: (1)a-b (2)b-a: " << endl;
		//Inserting selector s
		while (scanf_s("%d", &s) != 1 || s < 1 || s > 2 || getchar() != '\n') {
			cout << "The data was incorrect. Try again: " << endl;
			while (getchar() != '\n')
				;
		}
		if (s == 1) {
			//Printing difference of two matrices a-b
			cout << "Printing difference of two matrices:" << endl;
			DifferenceOfTwoMatrices(n, a, b);
		}
		else {
			//Printing difference of two matrices b-a
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
		//Dialog
		cout << "How do you want to devide the matrices: (1)a/b (2)b/a: " << endl;
		//Inserting selector s
		while (scanf_s("%d", &s) != 1 || s < 1 || s > 2 || getchar() != '\n') {
			cout << "The data was incorrect. Try again: " << endl;
			while (getchar() != '\n')
				;
		}
		if (s == 1) {
			//Printing quotient of two matrices a/b
			cout << "Printing quotient of two matrices:" << endl;
			QuotientOfTwoMatrices(n, a, b);
		}
		else {
			//Printing quotient of two matrices b/a
			cout << "Printing quotient of two matrices:" << endl;
			QuotientOfTwoMatrices(n, b, a);
		}
		break;
	default: ;
	}
	return 0;
}