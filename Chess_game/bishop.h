#pragma once
#include "piece.h"

class bishop : public piece
{
public:
	bishop()
	{
		_type = piece_type::Bishop;
	}
};
