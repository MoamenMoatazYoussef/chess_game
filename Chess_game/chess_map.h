#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "piece.h"

#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

#include "common.h"

#define BOARD_SIDE_LENGTH 8
#define BOARD_AREA (BOARD_SIDE_LENGTH*BOARD_SIDE_LENGTH)

#define KING_ROW_BLACK 0 //The top left of the board, start of 1st row of black, pawns
#define PAWN_ROW_BLACK 8 //The 2nd top left, start of 2nd row of black

#define PAWN_ROW_WHITE 48 //The 2nd bottom left, start of 1st row of white, pawns
#define KING_ROW_WHITE 56 //The bottom left of the board, start of 2nd row of white

class chess_map
{
public:
	chess_map();

	~chess_map()
	{
		delete piece_map;
		// Check deallocation of memory, lots of pointers
	}

	void init_black();
	void init_white();

	short get_position(short i, short j);

	piece* get_piece(short i, short j);

	void set_piece(short i, short j, piece* p);

	void set_piece(short pos, piece* p);

	void move_piece(piece* p, short new_position);

	void print_map()
	{
		for (int p = 0; p < BOARD_AREA; p++)
		{
			piece* pp = piece_map[p];
			pp->print_type();
			std::cout << " ";
			if (p % 10 == 0)
				std::cout << std::endl;
		}
	}

private:
	piece** piece_map = new piece*[BOARD_SIDE_LENGTH * BOARD_SIDE_LENGTH];
	// Item **m = new Item*[ n * n ];
	// if you want to access position 1, 2, and n = 5, then:
	// pos = (1 * 5) + 2;
	// Item * it = m[pos];
};