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
};
