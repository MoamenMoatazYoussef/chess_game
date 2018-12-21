#include <vector>
#include <string>

#include "piece.h"

#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include "common.h"

#define BOARD_SIDE_LENGTH 8

class chess_map
{
	piece** piece_map = new piece*[BOARD_SIDE_LENGTH * BOARD_SIDE_LENGTH];
	// Item **m = new Item*[ n * n ];
	////if you want to access position 1, 2, and n = 5, then:
	// pos = (1 * 5) + 2;
	// Item * it = m[pos];
	inline chess_map()
	{

	}

	inline int get_position(short i, short j);

	inline piece* get_piece(short i, short j);

	inline void set_piece(short i, short j, piece* p);

	inline void move_piece(piece* p, short new_position);
};