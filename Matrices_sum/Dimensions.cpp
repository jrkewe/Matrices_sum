#include <iostream>
#include "Dimensions.h"
using namespace std;

//Parameteric constructor
Dimensions::Dimensions(int r, int c) {
	numberOfRows = r;
	numberOfColumns = c;
}

//Destructor
Dimensions::~Dimensions() {}

//Get/Set for r
int Dimensions::getNumberOfRows() {
	return numberOfRows;
}
void Dimensions::setNumberOfRows(int r) {
	this->numberOfRows = r;
}

//Get/set for c
int Dimensions::getNumberOfColumns() {
	return numberOfColumns;
}
void Dimensions::setNumberOfColumns(int c) {
	this->numberOfColumns = c;
}
