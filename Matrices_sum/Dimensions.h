#ifndef DIMENSIONS
#define DIMENSIONS
#include <iostream>

class Dimensions {
	int row=0;
	int col=0;
public:
	//Constructors
	Dimensions() {};
	Dimensions(int r, int c);
	//Destructor
	~Dimensions();

	//Get/Set for r
	int getRow();
	void setRow(int r);

	//Get/set for c
	int getCol();
	void setCol(int c);
};
#endif
