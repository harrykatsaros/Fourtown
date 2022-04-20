#include <iostream>
#include <stdlib.h>
#include "Source.h"

using namespace std;


int dropMyDisk(Board& board, int column, Cells color)
{
	if (board._slots[0][column] != Empty)
	{
		std::cout << "It is full!" << std::endl;
		return -1;
	}
	else if (0 <= column && column <= 6)
	{
		for (int row = height - 1; row >= -1; row--)
		{
			if (row == 5)
			{
				if (board._slots[row][column] == Empty)
				{
					board._slots[row][column] = color;
					break;
				}
			}
			else if (board._slots[row + 1][column] != Empty && board._slots[row][column] == Empty)
			{
				board._slots[row][column] = color;
				break;
			}
		}
	}
	else
	{
		std::cout << "Invalid Move!" << std::endl;
		return -1;
	}
}

