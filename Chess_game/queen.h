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

	bool check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		return ((abs(r2 - r) == abs(c2 - c))
			|| ((r2 == r) || (c2 == c)));
			//Moves horizontal, vertical, and diagonal, so this is a combination of rook and bishop
			//TODO: I think there's a better way than this...
	}
};
