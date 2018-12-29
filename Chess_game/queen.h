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

	move_type check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		if ((abs(r2 - r) == abs(c2 - c)) || ((r2 == r) || (c2 == c)))
			return move_type::normal_move;
		return move_type::illegal_move;
	}
};
