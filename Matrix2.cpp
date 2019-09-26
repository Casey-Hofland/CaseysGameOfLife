#include <iostream>
#include <algorithm>
#include "Matrix2.h"
#include "Cell2.h"

void Matrix2::AddCellsAt( std::vector<std::pair<int , int>> points ) {
	for( auto it = points.begin(); it != points.end(); it++ ) {
		AddCellAt( ( *it ) );
	}
}

void Matrix2::Next() {
	for( auto it = aliveCells.begin(); it != aliveCells.end(); it++ ) {
		int pos = ( *it );
		Cell2* cell = summonedCells[ pos ];

		for( int y = pos - width; y <= pos + width && y < size; y += width ) {
			if( y < 0 ) continue;

			for( int x = ( ( y % width == 0 ) ? y : y - 1 ); ( x <= y + 1 ) && ( x % width != 0 ); x++ ) {
				if( x == pos ) continue;

				summonedCells[ x ]->status = CellStatus::Adjacent;
				summonedCells[ x ]->neighbours++;
			}
		}
	}
}

void Matrix2::Draw() {
	// Create a string filled with + on the iterators positions
	std::string drawString = std::string( width * height , drawDeadCell );

	for( auto it = aliveCells.begin(); it != aliveCells.end(); it++ ) {
		drawString[ ( *it ) ] = drawAliveCell;
	}
	for( int h = height; h > 0; h-- ) {
		drawString.insert( h * width , "\n" );
	}

	// Draw the field
	std::cout << drawString << std::endl;
}

void Matrix2::AddCellAt( std::pair<int , int> point ) {
	int pos = point.first + point.second * width;

	delete summonedCells[ pos ];
	( *summonedCells[ pos ] ) = Cell2();

	aliveCells.push_back( pos );
}
