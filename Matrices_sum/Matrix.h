#ifndef MATRIX
#define MATRIX

#include <vector> 
#include "Dimensions.h"

class Matrix {
private:
	Dimensions dimentionsObject;			
	std::vector<std::vector<int>> matrix ;

public:

	//Constructors
	Matrix() {};
	Matrix(Dimensions DIMOBJ, std::vector<std::vector<int>> mtx);
	Matrix(const Matrix& original);
	//Destructor
	~Matrix();

	//Get/Set - dimentions object
	Dimensions getDimentions();
	void setDimentions(int r, int c);

	//Get/Set - matrix
	std::vector<std::vector<int>> getMatrix();
	void setMatrix(std::vector<std::vector<int>> matrix);

	//Get/Set - elements
	int getElements(int i, int j);
	void setElements(int i, int j, int x);

	//Overloading operator =
	void operator =(const Matrix &A) {
		matrix = A.matrix;
	}

	//Print method
	void print();

	//Transposition method
	Matrix transposeMatrix(Matrix& A);

	int determinant(Matrix D);
};
#endif