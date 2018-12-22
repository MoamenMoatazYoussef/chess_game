#pragma once
#include "piece.h"

class pawn : public piece
{
public:
	pawn()
	{
		_type = piece_type::Pawn;
	}
};
