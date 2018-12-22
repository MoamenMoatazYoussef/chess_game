#pragma once
#include "piece.h"

class rook : public piece
{
public:
	rook()
	{
		_type = piece_type::Rook;
	}
};
