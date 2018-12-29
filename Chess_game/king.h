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

	move_type check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		if (abs(r2 - r) == 1 || abs(c2 - c) == 1)
			return move_type::normal_move;
		return move_type::illegal_move;
	}
};
