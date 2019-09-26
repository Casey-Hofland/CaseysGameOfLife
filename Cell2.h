#pragma once

enum CellStatus {
	None ,
	Alive ,
	Dead ,
	Adjacent
};

struct Cell2 {
public:
	Cell2() {
		status = CellStatus::Alive;
	}
	virtual ~Cell2() {}
	CellStatus status = CellStatus::None;
	int neighbours = 0;
};