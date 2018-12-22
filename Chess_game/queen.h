#pragma once
#include "piece.h"

class queen : public piece
{
public:
	queen()
	{
		_type = piece_type::Queen;
	}
};
