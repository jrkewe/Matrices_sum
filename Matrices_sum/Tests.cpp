#include <iostream>
#include "Tests.h"
#include "Dimensions.h"
#include "Texte.h"
using namespace std;


//Error checking loop
int testInt(int& n) {
	while (true) {
		try {
			cin.exceptions(ios::failbit | ios::badbit);
			cin >> n;
			break;
		}
		catch (exception&) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			texteErrorCheckingLoop();
		}
	}
	cout << "\n";
	return n;
}

//Exceptions handling
bool testMatricesSize(Dimensions A, Dimensions B) {
	try {
		if (A.getNumberOfRows() != B.getNumberOfRows() || A.getNumberOfColumns() != B.getNumberOfColumns()) {
			throw std::domain_error("Matrices are not the same size.");
		}
	}
	catch (std::domain_error& e) {
		texteExceptionsHandling();
		cout << e.what() << endl;
		return true;
	}
	return false;
}