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

	move_type check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		if ((r2 == r) || (c2 == c))
			return move_type::normal_move;
		return move_type::illegal_move;
	}
};
