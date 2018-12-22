#pragma once
#include "piece.h"

class king : public piece
{
public:
	king()
	{
		_type = piece_type::King;
	}

	king(player _p)
	{
		_type = piece_type::King;
		_player = _p;
	}
};
