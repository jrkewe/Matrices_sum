#ifndef DIMENSIONS
#define DIMENSIONS

class Dimensions {
	int numberOfRows=0;
	int numberOfColumns=0;

public:
	//Constructors
	Dimensions() {};
	Dimensions(int r, int c);
	//Destructor
	~Dimensions();

	//Get/Set for r
	int getNumberOfRows();
	void setNumberOfRows(int r);

	//Get/set for c
	int getNumberOfColumns();
	void setNumberOfColumns(int c);
};
#endif
