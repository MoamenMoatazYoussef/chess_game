#include "chess_map.h"

chess_map::chess_map()
{

}

int chess_map::get_position(short i, short j)
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

void chess_map::move_piece(piece* p, short new_position)
{
	short old_position = p->get_current_position();
	piece_map[new_position] = p;
	piece_map[old_position] = new piece(); //encapsulation: should map know the piece's type?
}