
#include <cstdio>
#include <cctype>
#include <iostream>
#include <vector>
#ifndef Matrix_H 
#define Matrix_H  

class Matrix {
private:
	int r = 0;		//rows
	int c = 0;		//columns
	vector<vector<int>> matrix;

public:

	//Constructors
	Matrix();
	Matrix(int r, int c, vector<vector<int>> matrix);
	Matrix(const Matrix& original);
	//Destructor
	~Matrix();

	//Get/Set for r
	int getr();
	void setr(int x);

	//Get/Set for c
	int getc();
	void setc(int c);

	//Get/Set for matrix
	vector<vector<int>> getmtx();
	void setmtx(vector<vector<int>> mtx);

	//Get/Set for elements of matrix
	int getelements(int i, int j);
	void setelements(int i, int j, int x);
};
#endif