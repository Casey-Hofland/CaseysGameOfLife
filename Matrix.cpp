#include <iostream>
#include <algorithm>
#include "Matrix.h"

Matrix::~Matrix() {}

void Matrix::TestMethod( std::vector<Cell> cells ) {
	this->cells = cells;
	CountNeighbours();
}

void Matrix::Next() {
	// Initialize a 2d vector to fill with ints corresponding to how many neighbours each item has
	std::vector<std::vector<int>> newCells( width );
	for( auto it = newCells.begin(); it != newCells.end(); it++ ) {
		( *it ) = std::vector<int>( height );
	}

	// Calculate the neighbours from each cell
	for( auto& cell : cells ) {
		int cellX = cell.x();
		int cellY = cell.y();

		for( int y = std::max( 0 , cellY - 1 ); y <= cellY + 1 && y < height; y++ ) {
			for( int x = std::max( 0 , cellX - 1 ); x <= cellX + 1 && x < width; x++ ) {
				if( y == cellY && x == cellX ) continue;
				newCells[ x ][ y ]++;
			}
		}

		int neighbours = cell.neighbours;
		newCells[ cellX ][ cellY ] = ( neighbours == 2 || neighbours == 3 ) ? 10 : -10;
	}

	// Reassign the new cells
	cells.clear();
	for( int w = 0; w < width; w++ ) {
		for( int h = 0; h < height; h++ ) {
			int i = newCells[ w ][ h ];
			if( i > 9 || i == 3 ) {
				cells.push_back( Cell( w , h ) );
			}
		}
	}

	CountNeighbours();
}

void Matrix::CountNeighbours() {
	for( auto it = cells.begin(); it != cells.end(); it++ ) {
		it->neighbours = 0;

		Cell cell = ( *it );
		
		int cellX = cell.x();
		int cellY = cell.y();

		for( int y = std::max( 0 , cellY - 1 ); y <= cellY + 1 && y < height; y++ ) {
			for( int x = std::max( 0 , cellX - 1 ); x <= cellX + 1 && x < width; x++ ) {
				if( y == cellY && x == cellX ) continue;

				if( std::find_if( cells.begin() , cells.end() ,
					[ x , y ]( Cell& c ) { return c.x() == x && c.y() == y; } )
					!= cells.end() ) {
					it->neighbours++;
				}
			}
		}
	}
}

void Matrix::Draw() {
	// Create an iterator of positions
	std::vector<int> liveCellPositions;
	for( auto& cell : cells ) {
		int cellPosition = cell.x() + cell.y() * width;
		liveCellPositions.push_back(cellPosition);
	}

	// Create a string filled with + on the iterators positions
	std::string drawString = std::string( width * height , ' ' );
	for( auto it = liveCellPositions.begin(); it != liveCellPositions.end(); it++ ) {
		drawString[ (*it) ] = '+';
	}
	for( int h = height; h > 0; h-- ) {
		drawString.insert( h * width , "\n" );
	}

	// Draw the field
	std::cout << drawString << std::endl;
}
