#pragma once
#include "piece.h"

class none : virtual public piece
{
public:
	none() //why can I use this here? "none() : _type(piece_type::None) {}"
	{
		_type = piece_type::None;
	}
};
