#pragma once
#include "piece.h"

class knight : public piece
{
public:
	knight()
	{
		_type = piece_type::Knight;
	}
};
