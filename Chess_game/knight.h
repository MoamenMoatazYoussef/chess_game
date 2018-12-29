#pragma once
#include "piece.h"

class knight : public piece
{
public:
	knight()
	{
		_type = piece_type::Knight;
	}

	knight(player _p)
	{
		_type = piece_type::Knight;
		_player = _p;
	}

	knight(short r, short c) //TODO: for unit testing only, should be removed after
	{
		_row = r;
		_col = c;
	}

	move_type check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();

		short Xsquared  = pow((r2 - r), 2);
		short Ysquared  = pow((c2 - c), 2);
		if((Xsquared + Ysquared) == 5)
			return move_type::normal_move;
		return move_type::illegal_move;
	}
};
