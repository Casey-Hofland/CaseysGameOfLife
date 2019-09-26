#pragma once

struct Cell {
public:
	Cell( int x , int y ) {
		_x = x;
		_y = y;
	}
	virtual ~Cell() {}
	const int x(){ return _x; }
	const int y(){ return _y; }
	int neighbours = 0;

private:
	int _x;
	int _y;
};