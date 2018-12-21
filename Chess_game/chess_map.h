#pragma once

#include <vector>
#include <string>

#include "piece.h"

#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

#include "common.h"

#define BOARD_SIDE_LENGTH 8

#define KING_ROW_BLACK 0 //The top left of the board, start of 1st row of black, pawns
#define PAWN_ROW_BLACK 8 //The 2nd top left, start of 2nd row of black

#define PAWN_ROW_WHITE 48 //The 2nd bottom left, start of 1st row of white, pawns
#define KING_ROW_WHITE 56 //The bottom left of the board, start of 2nd row of white

class chess_map
{
public:
	inline chess_map();

	~chess_map()
	{
		delete piece_map;
		// Check deallocation of memory, lots of pointers
	}

	inline void init_black();
	inline void init_white();

	inline short get_position(short i, short j);

	inline piece* get_piece(short i, short j);

	inline void set_piece(short i, short j, piece* p);

	inline void set_piece(short pos, piece* p);

	inline void move_piece(piece* p, short new_position);

private:
	piece** piece_map = new piece*[BOARD_SIDE_LENGTH * BOARD_SIDE_LENGTH];
	// Item **m = new Item*[ n * n ];
	// if you want to access position 1, 2, and n = 5, then:
	// pos = (1 * 5) + 2;
	// Item * it = m[pos];
};