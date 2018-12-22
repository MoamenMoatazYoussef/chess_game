#include "chess_map.h"

//chess_map::chess_map()
//{}	//TODO: write the constructor here, why not when we initialize chess_map in header?

inline void chess_map::init_black()
{
	piece_map[BLACK_PAWN_ROW][0] = new pawn();
	piece_map[BLACK_PAWN_ROW][1] = new pawn();
	piece_map[BLACK_PAWN_ROW][2] = new pawn();
	piece_map[BLACK_PAWN_ROW][3] = new pawn();
	piece_map[BLACK_PAWN_ROW][4] = new pawn();
	piece_map[BLACK_PAWN_ROW][5] = new pawn();
	piece_map[BLACK_PAWN_ROW][6] = new pawn();
	piece_map[BLACK_PAWN_ROW][7] = new pawn();

	piece_map[BLACK_KING_ROW][0] = new rook();
	piece_map[BLACK_KING_ROW][1] = new knight();
	piece_map[BLACK_KING_ROW][2] = new bishop();
	piece_map[BLACK_KING_ROW][3] = new queen();
	piece_map[BLACK_KING_ROW][4] = new king();
	piece_map[BLACK_KING_ROW][5] = new bishop();
	piece_map[BLACK_KING_ROW][6] = new knight();
	piece_map[BLACK_KING_ROW][7] = new rook();
}

inline void chess_map::init_white()
{
	piece_map[WHITE_PAWN_ROW][0] = new pawn();
	piece_map[WHITE_PAWN_ROW][1] = new pawn();
	piece_map[WHITE_PAWN_ROW][2] = new pawn();
	piece_map[WHITE_PAWN_ROW][3] = new pawn();
	piece_map[WHITE_PAWN_ROW][4] = new pawn();
	piece_map[WHITE_PAWN_ROW][5] = new pawn();
	piece_map[WHITE_PAWN_ROW][6] = new pawn();
	piece_map[WHITE_PAWN_ROW][7] = new pawn();

	piece_map[WHITE_KING_ROW][0] = new rook();
	piece_map[WHITE_KING_ROW][1] = new knight();
	piece_map[WHITE_KING_ROW][2] = new bishop();
	piece_map[WHITE_KING_ROW][3] = new queen();
	piece_map[WHITE_KING_ROW][4] = new king();
	piece_map[WHITE_KING_ROW][5] = new bishop();
	piece_map[WHITE_KING_ROW][6] = new knight();
	piece_map[WHITE_KING_ROW][7] = new rook();
}

void chess_map::init_middle()
{
	for (int row = BLACK_PAWN_ROW + 1; row < WHITE_PAWN_ROW + 1; row++)
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
			piece_map[row][col] = new piece();
}

inline piece* chess_map::get_piece(short row, short col)
{
	return piece_map[row][col];
}

short chess_map::get_row(piece* p)
{
	return p->get_row();
}

short chess_map::get_col(piece* p)
{
	return p->get_col();
}

inline void chess_map::set_piece(short row, short col, piece* p)
{
	piece_map[row][col] = p;
}

inline void chess_map::move_piece(short new_row, short new_col, piece* p)
{
	short old_row = get_row(p);
	short old_col = get_col(p);
	piece_map[new_row][new_col] = p;
	piece_map[old_row][old_col] = new piece(); //encapsulation: should map know the piece's type?
}
