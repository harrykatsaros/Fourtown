#pragma once

const int width = 7;

const int height = 6;

enum Cells {
	Red = 1,
	Blue = -1,
	Empty = 0
};

struct Board {
	Cells _slots[height][width];
};


int dropMyDisk(Board& board, int column, Cells color);
