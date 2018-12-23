#pragma once
#include "piece.h"

class bishop : public piece
{
public:
	bishop()
	{
		_type = piece_type::Bishop;
	}

	bishop(player _p)
	{
		_type	= piece_type::Bishop;
		_player = _p;
	}

	bool check_move(short r2, short c2)
	{
		short r = get_row();
		short c = get_col();
		return (abs(r2 - r) == abs(c2 - c)); 
			//moves diagonal, so for example it can move from (3,4) to (1,2) or (1,6) or (5,2) or (5,6)
			//in all cases, absolute difference of rows is the same as absolute difference of columns.
	}
};
