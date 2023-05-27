// The program adds to matrices and writes their sum on the screen. It takes n 
// as the dimensions of two matrices and then asks for values to fill them up.
// Then we will be able to see a visual representation of both matrices and their 
// sum on the screen.

#include <cstdio>
#include <iostream>
using namespace std;
#define max 20

void InsertValue(int n, int a[max][max]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << "[" << i << "][" << j << "]:";
			while (scanf_s("%d", &a[i][j]) != 1 || cin.get()!='\n') {
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
			cout << a[i][j] << " ";
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
		 << "Enter the size of matrices : " << endl;

	//Inserting size n
	while (scanf_s("%d", &n) != 1 || getchar() != '\n') {
		cout << "The data was incorrect. Try again: " << endl;
		while (getchar() != '\n')
			;
	}

	//Inserting - elements of matrix a
	cout << "Inserting elements of matrix:" << endl;
	InsertValue(n,a);

	//Inserting - elements of matrix b
	cout << "Inserting elements of matrix:" << endl;
	InsertValue(n,b);

	//Printing matrix a
	cout << "Printing matrix:" << endl;
	PrintMatrix(n,a);

	//Printing matrix b
	cout << "Printing matrix:" << endl;
	PrintMatrix(n,b);
	
	//Printing sum of two matrices
	cout << "Printing sum of two matrices:" << endl;
	SumOfTwoMatrices(n,a,b);

	return 0;
}