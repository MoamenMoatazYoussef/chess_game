#pragma once
#include <string>
#include "common.h"

class piece
{
public:
	piece()
	{
		_type = piece_type::none;
	}
	piece(piece_type _t, player _p, short _pos)
	{
		_position = _pos;
		_player = _p;
		_type = _t;
	}
	~piece();

	short get_current_position() { return _position; }
	player get_player() { return _player; }
	piece_type get_piece_type() { return _type; }

private:
	piece_type _type;
	player _player;
	short _position;
};