#pragma once
#include "piece.h"

class rook : public piece
{
public:
	rook()
	{
		_type = piece_type::Rook;
	}

	rook(player _p)
	{
		_type = piece_type::Rook;
		_player = _p;
	}

	rook(short r, short c) //TODO: for unit testing only, should be removed after
	{
		_row = r;
		_col = c;
	}

	bool check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		return ((r2 == r) || (c2 == c)); //moves vertical or horizontal, so one must be constant
		//Test cases at r,c = 3, 3:
		// r2 = 3, c2 = 6
		// r2 = 6, c2 = 3
		// r2 = 3, c2 = 1
		// r2 = 1, c2 = 3
		// r2 = 4, c2 = 4
		// r2 = 2, c2 = 5
	}
};
