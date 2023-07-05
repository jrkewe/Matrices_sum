#include <iostream>
#include <deque>
#include "Dimensions.h"
#include "Matrix.h"
using namespace std;

//Constructors
Matrix::Matrix(Dimensions dimentionsobject, std::vector<std::vector<int>> matrix) : dimentionsObject(dimentionsobject), matrix(matrix) {}
Matrix::Matrix(const Matrix& original) : dimentionsObject(original.dimentionsObject), matrix(original.matrix) {}
Matrix::~Matrix() {}

//Get/Set - dimentions object
Dimensions Matrix::getDimentions() {
	return dimentionsObject;
}
void Matrix::setDimentions(int r, int c) {
	dimentionsObject = {r,c};
}

//Get/Set - matrix
vector<vector<int>> Matrix::getMatrix() {
	return matrix;
}
void Matrix::setMatrix(vector<vector<int>> Matrix) {
	matrix = Matrix;
}

//Get/Set - elements
int Matrix::getElements(int i, int j) {
	return matrix[i][j];
}
void Matrix::setElements(int i, int j, int x) {
	matrix[i][j] = x;
}

//Print method
void Matrix::print() {
	for (int i = 0;i < dimentionsObject.getNumberOfRows();i++) {
		for (int j = 0;j < dimentionsObject.getNumberOfColumns();j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}

//Transposition method
Matrix Matrix::transposeMatrix(Matrix& A) {
	Matrix R;
	int n = A.getDimentions().getNumberOfRows();
	int m = A.getDimentions().getNumberOfColumns();
	R.setMatrix(vector<vector<int>>(m, vector<int>(n)));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			R.setElements(i, j, A.getElements(j, i));
		}
	}
	return R;
}

//Determinant of matrix
int Matrix::determinant(Matrix D) {

	//Pascal's triangle
	vector <int> vector2 = { 1,2,1 };
	if (D.getDimentions().getNumberOfRows() > 2) {
		vector <int> vector1{ 1 };

		for (int i = 0; i < D.getDimentions().getNumberOfRows() - 2; i++) {

			for (int j = 0; j < vector2.size() - 1; j++) {
				vector1.push_back(vector2[j] + vector2[j + 1]);
			}
			vector1.push_back(1);
			vector2 = vector1;
			vector1.clear();
			vector1.push_back(1);
		}
	}
	for (int i = 0; i < vector2.size(); i++) {
		cout << vector2[i] << " ";
	}
	cout << "\n";

	int sum1 = 0;
	int sum2 = 0;
	int product = 1;
	deque <int> dq;
	vector <int> vec;

	//new deck
	for (int i = 0;i < D.getDimentions().getNumberOfRows();i++) {
		dq.push_back(i);
	}

	//SUM
	for (int j = 0;j < D.getDimentions().getNumberOfRows();j++) {
		product = 1;

		for (int i = 0;i < D.getDimentions().getNumberOfRows();i++) {
			//if i==dq[i]
			if (i == dq[i]) {			//polynomial

				for (int w = 0; w < vector2.size(); w++) {

					for (int p = 0;p < vector2[w];p++) {

						product = 1;
						for (int q = 0;q < D.getDimentions().getNumberOfRows() - w;q++) {
							if (p + q >= D.getDimentions().getNumberOfRows() - 1 && q != D.getDimentions().getNumberOfRows() - w - 1) {
								product *= D.getElements(q + 1, q + 1);
							}
							else {
								product *= D.getElements(q, q);
							}
						}
						sum1 += product;
					}
					vec.push_back(sum1);
					product = 1;
					sum1 = 0;
				}
			}
			cin >> sum1;


			//if i!=dq[i]
		/*	if (i!=dq[i]) {
				product *= D.getElements(i, dq[i]);

			}*/
		}

		cout << endl;


		int x = dq[0];
		dq.pop_front();
		dq.push_back(x);



		sum1 += product;
	}

	//reversion of deck
	for (int j = 0;j < D.getDimentions().getNumberOfRows();j++) {
		dq[j] = D.getDimentions().getNumberOfRows() - 1 - j;
	}

	//SUM2
	for (int j = 0;j < D.getDimentions().getNumberOfRows();j++) {
		product = 1;
		for (int i = D.getDimentions().getNumberOfRows() - 1;i > -1;i--) {
			product *= D.getElements(i, dq[i]);
		}
		int x = dq[D.getDimentions().getNumberOfRows() - 1];
		dq.pop_back();
		dq.push_front(x);

		sum2 += product;
	}

	return sum1 - sum2;
};
