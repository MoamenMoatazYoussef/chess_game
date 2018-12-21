#include "chess_map.h"

chess_map::chess_map()
{
	init_black();
	init_white();
}

short chess_map::get_position(short i, short j)
{
	return ((i * BOARD_SIDE_LENGTH) + j);
}

piece* chess_map::get_piece(short i, short j)
{
	return piece_map[get_position(i, j)];
}

void chess_map::set_piece(short i, short j, piece* p)
{
	piece_map[get_position(i, j)] = p;
}

void chess_map::set_piece(short pos, piece* p)
{
	piece_map[pos] = p;
}

void chess_map::move_piece(piece* p, short new_position)
{
	short old_position = p->get_current_position();
	piece_map[new_position] = p;
	piece_map[old_position] = new piece(); //encapsulation: should map know the piece's type?
}

void chess_map::init_black()
{
	piece_map[PAWN_ROW_BLACK]     = new pawn();
	piece_map[PAWN_ROW_BLACK + 1] = new pawn();
	piece_map[PAWN_ROW_BLACK + 2] = new pawn();
	piece_map[PAWN_ROW_BLACK + 3] = new pawn();
	piece_map[PAWN_ROW_BLACK + 4] = new pawn();
	piece_map[PAWN_ROW_BLACK + 5] = new pawn();
	piece_map[PAWN_ROW_BLACK + 6] = new pawn();
	piece_map[PAWN_ROW_BLACK + 7] = new pawn();

	piece_map[KING_ROW_BLACK]      = new rook();
	piece_map[KING_ROW_BLACK + 1]  = new knight();
	piece_map[KING_ROW_BLACK + 2]  = new bishop();
	piece_map[KING_ROW_BLACK + 3]  = new queen();
	piece_map[KING_ROW_BLACK + 4]  = new king();
	piece_map[KING_ROW_BLACK + 5]  = new bishop();
	piece_map[KING_ROW_BLACK + 6]  = new knight();
	piece_map[KING_ROW_BLACK + 7]  = new rook();
}

void chess_map::init_white()
{
	piece_map[PAWN_ROW_WHITE]     = new pawn();
	piece_map[PAWN_ROW_WHITE + 1] = new pawn();
	piece_map[PAWN_ROW_WHITE + 2] = new pawn();
	piece_map[PAWN_ROW_WHITE + 3] = new pawn();
	piece_map[PAWN_ROW_WHITE + 4] = new pawn();
	piece_map[PAWN_ROW_WHITE + 5] = new pawn();
	piece_map[PAWN_ROW_WHITE + 6] = new pawn();
	piece_map[PAWN_ROW_WHITE + 7] = new pawn();
					   
	piece_map[KING_ROW_WHITE]     = new rook();
	piece_map[KING_ROW_WHITE + 1] = new knight();
	piece_map[KING_ROW_WHITE + 2] = new bishop();
	piece_map[KING_ROW_WHITE + 3] = new queen();
	piece_map[KING_ROW_WHITE + 4] = new king();
	piece_map[KING_ROW_WHITE + 5] = new bishop();
	piece_map[KING_ROW_WHITE + 6] = new knight();
	piece_map[KING_ROW_WHITE + 7] = new rook();
}