#pragma once

#include <map>
#include <vector>
#include "Cell2.h"

class Matrix2 {
public:
	Matrix2( int size ) {
		this->width = size;
		this->height = size;
		this->size = size * size;
	}
	Matrix2( int width , int height ) {
		this->width = width;
		this->height = height;
		this->size = width * height;
	}
	virtual ~Matrix2();
	void AddCellsAt( std::vector<std::pair<int , int>> points );
	void Next();
	void Draw();

private:
	int width;
	int height;
	int size;
	std::map<int , Cell2*> summonedCells;
	std::vector<int> aliveCells;
	void AddCellAt( std::pair<int , int> point );

	const char drawDeadCell = ' ';
	const char drawAliveCell = '+';
};