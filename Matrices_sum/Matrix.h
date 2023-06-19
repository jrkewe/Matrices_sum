
#include <cstdio>
#include <cctype>
#include <iostream>
#include <vector> 
#pragma
class Matrix {
private:
	int r;		//rows
	int c;		//columns
	std::vector<std::vector<int>> matrix ;

public:

	//Constructors
	//Default constructor
	Matrix() {
		r = 0;
		c = 0;
		for (int i = 0;i < r;i++) {
			for (int j = 0;j < c;i++) {
				matrix[i][j] = 0;
			}
		}
	}
	Matrix(int r, int c, std::vector<std::vector<int>> matrix);
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
	std::vector<std::vector<int>> getmtx();
	void setmtx(std::vector<std::vector<int>> mtx);

	//Get/Set for elements of matrix
	int getelements(int i, int j);
	void setelements(int i, int j, int x);
};