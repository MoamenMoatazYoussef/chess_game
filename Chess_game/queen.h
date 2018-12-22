#pragma once
#include "piece.h"

class queen : public piece
{
public:
	queen()
	{
		_type = piece_type::Queen;
	}

	queen(player _p)
	{
		_type = piece_type::Queen;
		_player = _p;
	}
};
