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

	bool check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		return ((r2 == r) || (c2 == c)); //moves vertical or horizontal, so one must be constant
	}
};
