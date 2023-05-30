#include <cstdio>
#include <cctype>
#include <iostream>
#include "Declarations.h"
using namespace std;

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

void InsertValue(int n, int a[dim][dim]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << "[" << i << "][" << j << "]: ";
			while (true) {
				try {
					cin.exceptions(ios::failbit | ios::badbit);
					cin >> a[i][j];
					break;
				}
				catch (exception&) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Try again: ";
				}
			}
		}
	}
	cout << "\n";
}

void PrintMatrix(int n, int a[dim][dim]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void SumOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] + b[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << endl;
}

void DifferenceOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] - b[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << endl;
}

void ProductOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << a[i][j] * b[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << endl;
}

void QuotientOfTwoMatrices(int n, int a[dim][dim], int b[dim][dim]) {
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
