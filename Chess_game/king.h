#pragma once
#include "piece.h"

class king : public piece
{
public:
	king()
	{
		_type = piece_type::King;
	}

	king(player _p)
	{
		_type = piece_type::King;
		_player = _p;
	}

	king(short r, short c) //TODO: for unit testing only, should be removed after
	{
		_row = r;
		_col = c;
	}

	bool check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		return ((abs(r2 - r) == 1 || abs(c2 - c) == 1));
			//Moves horizontal, vertical, and diagonal, by step 1
			//So, check if difference of one of them is 1, if one or both then is correct
		//Test cases at r,c = 3, 3:
		// r2 = 3, c2 = 4
		// r2 = 4, c2 = 4
		// r2 = 4, c2 = 3
		// r2 = 4, c2 = 2
		// r2 = 3, c2 = 2
		// r2 = 2, c2 = 2
		// r2 = 2, c2 = 3
		// r2 = 2, c2 = 4
		// r2 = 5, c2 = 4
		// r2 = 3, c2 = 5
	}
};
