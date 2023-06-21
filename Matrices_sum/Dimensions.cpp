#include <iostream>
#include "Dimensions.h"
using namespace std;

//Parameterized constructor
Dimensions::Dimensions(int r, int c) {
	this->row = r;
	this->col = c;
}

//Destructor
Dimensions::~Dimensions() {}

//Get/Set for r
int Dimensions::getRow() {
	return row;
}
void Dimensions::setRow(int r) {
	this->row = r;
}

//Get/set for c
int Dimensions::getCol() {
	return col;
}
void Dimensions::setCol(int c) {
	this->col = c;
}
