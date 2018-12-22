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
};
