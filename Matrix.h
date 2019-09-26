#pragma once

#include <vector>
#include "Cell.h"

class Matrix {
public:
	Matrix( int size ) {
		DeclareMatrix( size , size );
		this->width = size;
		this->height = size;
	}
	Matrix( int width , int height ) {
		DeclareMatrix( width , height );
		this->width = width;
		this->height = height;
	}
	/*
	Grid ( int size , bool wrap ) {
		DeclareMatrix( size , size );
		this->width = size;
		this->height = size;
		this->wrap = wrap;
	}
	Grid ( int width , int height , bool wrap ) {
		DeclareMatrix( width , height );
		this->width = width;
		this->height = height;
		this->wrap = wrap;
	}
	*/
	virtual ~Matrix();
	void Next();
	void CountNeighbours();
	void Draw();
	void TestMethod( std::vector<Cell> cells );

private:
	int width;
	int height;
	bool wrap;
	std::vector<Cell> cells;

	Cell*** matrix;
	void DeclareMatrix( int rows , int cols ) {
		matrix = new Cell ** [ rows ];
		for( int r = 0; r < rows; r++ ) {
			matrix[ r ] = new Cell* [ cols ];
			for( int c = 0; c < cols; c++ ) {
				matrix[ r ][ c ] = new Cell( r , c );
			}
		}
	}
};