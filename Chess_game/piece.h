#pragma once
#include <string>
#include <iostream>
#include "common.h"

class piece
{
public:
	piece() : _type(piece_type::None) { }

	//piece(player _p) : _type(piece_type::None), _player(_p) { }

	piece(short _r, short _c) :
		_row(_r), _col(_c) { }

	piece(piece_type _t, player _p, short _r, short _c) : 
		_row(_r), _col(_c), _type(_t), _player(_p) { }

	~piece() { }

	short get_row() { return _row; }
	short get_col() { return _col; }
	player get_player() { return _player; }
	piece_type get_piece_type() { return _type; }

	void set_row(short r) { _row = r; }
	void set_col(short c) { _col = c; }
	void set_player(player p) { _player = p; }
	void set_piece_type(piece_type t) { _type = t; }

	void print_type() { std::cout << (char)_type << " ";  }

	virtual bool check_move(short r2, short c2) { return false; } //TODO: remove this return, what is that?

protected:
	piece_type _type;
	player _player;
	short _row;
	short _col;
};