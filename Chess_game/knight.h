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
};
