#pragma once
#include "piece.h"

class queen : public piece
{
public:
	queen()
	{
		_type = piece_type::Queen;
	}

	queen(player _p)
	{
		_type = piece_type::Queen;
		_player = _p;
	}

	queen(short r, short c) //TODO: for unit testing only, should be removed after
	{
		_row = r;
		_col = c;
	}

	bool check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		return ((abs(r2 - r) == abs(c2 - c))
			|| ((r2 == r) || (c2 == c)));
			//Moves horizontal, vertical, and diagonal, so this is a combination of rook and bishop
			//TODO: I think there's a better way than this...

		//Test cases at r = 3, c = 3:
		//Both rook and bishop test cases
	}
};
