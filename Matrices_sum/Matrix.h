#include <vector> 
#include "Dimensions.h"

class Matrix {
private:
	Dimensions dimobj;			
	std::vector<std::vector<int>> matrix ;

public:

	//Constructors
	Matrix() {};
	Matrix(Dimensions DIMOBJ, std::vector<std::vector<int>> mtx);
	Matrix(const Matrix& original);
	//Destructor
	~Matrix();

	//Get/Set for obj.:dimensions
	Dimensions getDim();
	void setDim(int r, int c);

	//Get/Set for matrix
	std::vector<std::vector<int>> getMtx();
	void setMtx(std::vector<std::vector<int>> mtx);

	//Get/Set for elements of matrix
	int getElements(int i, int j);
	void setElements(int i, int j, int x);

	//Overloading operator =
	void operator =(const Matrix &A) {
		matrix = A.matrix;
	}

	//Transposition method
	Matrix T(Matrix& A);

	//print method
	void print(Matrix A);
};

