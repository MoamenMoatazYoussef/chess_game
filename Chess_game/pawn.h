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

	bool check_move(short r2, short c2)
	{ 
		short r = get_row();
		short c = get_col();
		//std::cout << r << "   " << c << "   " << r2 << "   " << c2 << "   " << get_player() << std::endl;
		return ((r2 == r + 1*get_player()) && (c2 == c)); 
			//moves vertically by 1, so row increases, col doesn't change
			//multiply by piece_type because white(-1) moves up, black(1) moves down, see common.h

		//Test cases at r = 3, c = 3:
		// r2 = 4, c2 = 3
		// r2 = 2, c2 = 3
		// r2 = 5, c2 = 3
		// r2 = 4, c2 = 4
	}
};
