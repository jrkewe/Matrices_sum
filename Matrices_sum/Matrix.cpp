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
					cout << "Rozmiar wektora:" << vector2.size() << endl;

					cout << "Warunek for dla p:" << vector2[w] << endl;
					for (int p = 0;p < vector2[w];p++) {

						if (w == vector2.size() - 1) {
							sum1 = 1;
							break;
						}

						product = 1;
						cout << "Warunek for dla q:" << D.getDimentions().getNumberOfRows() - w << endl;


							for (int q = 0;q < D.getDimentions().getNumberOfRows() -w;q++) {
								cout << "p:" << p << "  q:" << q << endl;

								if (D.getDimentions().getNumberOfRows() - w == 1) {
									product *= D.getElements(p, p);
									cout << "ppElement:" << D.getElements(p, p) << endl;
								}

								else if (D.getDimentions().getNumberOfRows() - w == 2) {
									cout << "jestem" << endl;
									if (q == 0) {
										cout << "jestemq=0" << endl;
										int z = D.getDimentions().getNumberOfRows() - 1;
										cout << "jestem z=" <<  z<< "p:" << p << endl;
										if (p < z) {
											product *= D.getElements(0, 0);
											cout << "00Element:" << D.getElements(0, 0) << endl;
										}
										else {
											int m = z;
											for (int i = 1; i < z; i++) {
												m += z - i;
												if (p<m) {
													product *= D.getElements(i, i);
													cout << "iElement:" << D.getElements(i, i) << endl;
												}
											}

										}
									}
									else if (q==1) {
										cout << "jestemq=1" << endl;
										int z = D.getDimentions().getNumberOfRows()-1 ;
										if (z==1) {
											product *= D.getElements(z, z);
											cout << "zzElement:" << D.getElements(z,z) << endl;
											break;
										}
										cout << "jestem z=" << z << endl;
										int i;
											int m = z;
											for (i = 1; i < z; i++) {
												m += z - i;
												if (p < m) {
													//ile zbiorow miescilo sie przed p?
													int count = 0;
													for (int j = i;j>0;j--) {
														//ile elementow bylo w tych wszystkich zbiorach
														count += z - j;
													}
													product*= D.getElements(p-count+1, p - count + 1);
													cout << "p-cElement:" << D.getElements(p - count + 1, p - count + 1) << endl;
													break;
												}
											}
									}
								}
						
								else if (p + q >= D.getDimentions().getNumberOfRows() - 1) {
									if (q== D.getDimentions().getNumberOfRows() - 1) {
										product *= D.getElements(q , q );
										cout << "qqElement:" << D.getElements(q , q ) << endl;
									}
									else {
										product *= D.getElements(q + 1, q + 1);
										cout << "q-1Element:" << D.getElements(q + 1, q + 1) << endl;
									}
								}

								else {
									product *= D.getElements(q, q);
									cout << "qq2Element:" << D.getElements(q, q) << endl;
								}
							}
							sum1 += product;
						}


					cout << "Sum1: " << sum1 << endl;
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
