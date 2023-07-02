#include <string>
#include <iostream>
#include "Texte.h"

void texteFroTheUser() {
	std::cout << "The program allows to: add, subtract, multiply, divide, transpose matrices.\n\n" << std::endl;
}

void texteMatrixA(int y) {
	enum x { size, elements };
	if (y == size) {
		std::cout << "Size of matrix A: ";
	}
	else if (y == 2) {
		std::cout << "Elements of matrix A:\n";
	}
}

void texteMatrixB(int y) {
	enum x { size, elements };
	if (y == size) {
		std::cout << "Size of matrix B: ";
	}
	else if (y == elements) {
		std::cout << "Elements of matrix B:\n";
	}
}

void texteSwitch() {
	std::cout << "The program respectively allows to : (1) + (2) - (3) * (4) / (5)T(6)Update matrix A(7)Update matrix B(8)Quit\n"
		<< "Select an option:" << std::endl;
}

void texteAddition() {
	std::cout << "Printing sum of two matrices:" << std::endl;
}

void texteSubstraction(int i) {
	enum j { menu, result };
	if (i == menu) {
		std::cout << "How do you want to subtract the matrices: (1)a-b (2)b-a: " << std::endl;
	}
	else if (i == result) {
		std::cout << "Printing difference of two matrices:" << std::endl;
	}
}

void texteMultiplication(int i) {
	enum j { menu, factor, result };
	if (i == menu) {
		std::cout << "How do you want to multiply the matrices: (1)a*b (2)b*a (3)a*C (4)b*C : " << std::endl;
	}
	else if (i == factor) {
		std::cout << "Enter the factor:";
	}
	else if (i == result) {
		std::cout << "Printing product:\n" << std::endl;
	}
}

void texteDivision(int i) {
	enum j { menu, result};
	if (i == menu) {
		std::cout << "Which matrix you want to devide: (1)a (2)b: " << std::endl;
	}
	else if (i == result) {
		std::cout << "Printing quotient:\n" << std::endl;
	}
}

void texteTransposition() {
	std::cout << "Which matrix you want to transpose: (1)a (2)b: " << std::endl;
}

void texteQuit() {
	std::cout << "Quit";
}

void texteErrorCheckingLoop() {
	std::cout << "Try again: ";
}

void texteExceptionsHandling() {
	std::cout << "Domain error: ";
}


