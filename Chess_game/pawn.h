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

	bool check_move(short r2, short c2)
	{ 
		short r = get_row();
		short c = get_col();
		return ((r2 == r + 1*get_piece_type()) && (c2 == c)); 
			//moves vertically by 1, so row increases, col doesn't change
			//multiply by piece_type because white(-1) moves up, black(1) moves down, see common.h
	}
};
