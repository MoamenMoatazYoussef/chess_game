#pragma once
#include "piece.h"

class pawn : public piece
{
public:
	pawn()
	{
		_type = piece_type::Pawn;
	}

	pawn(player _p)
	{
		_type = piece_type::Pawn;
		_player = _p;
	}

	pawn(short r, short c) //TODO: for unit testing only, should be removed after
	{
		_row = r;
		_col = c;
	}

	pawn(player p, short r, short c) //TODO: for unit testing only, should be removed after
	{
		_row = r;
		_col = c;
		_player = p;
	}

	move_type check_move(short r2, short c2)
	{ 
		short r = get_row();
		short c = get_col();

		if ((r2 == r + 1 * get_player()) && (c2 == c))
			return move_type::normal_move;

		else if ((r2 == r + 1 * get_player()) && (abs(c2 - c) == 1)) //TODO: a better way than these if-statements
			return move_type::capture_move;

		return move_type::illegal_move;
	}
};
