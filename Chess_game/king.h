#pragma once
#include "piece.h"

class king : public piece
{
public:
	king()
	{
		_type = piece_type::King;
	}
};
