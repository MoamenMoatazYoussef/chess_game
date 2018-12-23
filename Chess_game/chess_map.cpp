#include "chess_map.h"

//chess_map::chess_map()
//{}	//TODO: write the constructor here, why not when we initialize chess_map in header?

void chess_map::init_map() //TODO: find another way than this O(8^2) thing, although isn't bad for a chess game...
{
	for (int row = BLACK_PAWN_ROW + 1; row < WHITE_PAWN_ROW + 1; row++)
		for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
			piece_map[row][col] = new none();

	init_black();
	init_white();
}

inline void chess_map::init_black() //TODO: there has to be a better, more compact way than this...
{
	piece_map[BLACK_PAWN_ROW][0] = new pawn(player::black); //These can be vectorized for sure
	piece_map[BLACK_PAWN_ROW][1] = new pawn(player::black);
	piece_map[BLACK_PAWN_ROW][2] = new pawn(player::black);
	piece_map[BLACK_PAWN_ROW][3] = new pawn(player::black);
	piece_map[BLACK_PAWN_ROW][4] = new pawn(player::black);
	piece_map[BLACK_PAWN_ROW][5] = new pawn(player::black);
	piece_map[BLACK_PAWN_ROW][6] = new pawn(player::black);
	piece_map[BLACK_PAWN_ROW][7] = new pawn(player::black);

	piece_map[BLACK_KING_ROW][0] = new rook(player::black);
	piece_map[BLACK_KING_ROW][1] = new knight(player::black);
	piece_map[BLACK_KING_ROW][2] = new bishop(player::black);
	piece_map[BLACK_KING_ROW][3] = new queen(player::black);
	piece_map[BLACK_KING_ROW][4] = new king(player::black);
	piece_map[BLACK_KING_ROW][5] = new bishop(player::black);
	piece_map[BLACK_KING_ROW][6] = new knight(player::black);
	piece_map[BLACK_KING_ROW][7] = new rook(player::black);
}

inline void chess_map::init_white() //TODO: same, a better way, and vectorization
{
	piece_map[WHITE_PAWN_ROW][0] = new pawn(player::white);
	piece_map[WHITE_PAWN_ROW][1] = new pawn(player::white);
	piece_map[WHITE_PAWN_ROW][2] = new pawn(player::white);
	piece_map[WHITE_PAWN_ROW][3] = new pawn(player::white);
	piece_map[WHITE_PAWN_ROW][4] = new pawn(player::white);
	piece_map[WHITE_PAWN_ROW][5] = new pawn(player::white);
	piece_map[WHITE_PAWN_ROW][6] = new pawn(player::white);
	piece_map[WHITE_PAWN_ROW][7] = new pawn(player::white);

	piece_map[WHITE_KING_ROW][0] = new rook(player::white);
	piece_map[WHITE_KING_ROW][1] = new knight(player::white);
	piece_map[WHITE_KING_ROW][2] = new bishop(player::white);
	piece_map[WHITE_KING_ROW][3] = new queen(player::white);
	piece_map[WHITE_KING_ROW][4] = new king(player::white);
	piece_map[WHITE_KING_ROW][5] = new bishop(player::white);
	piece_map[WHITE_KING_ROW][6] = new knight(player::white);
	piece_map[WHITE_KING_ROW][7] = new rook(player::white);
}

piece* chess_map::get_piece(short row, short col)
{
	return piece_map[row][col];
}

void chess_map::set_piece(short row, short col, piece* p)
{
	piece_map[row][col] = p;
}

short chess_map::get_row(piece* p)
{
	return p->get_row();
}

short chess_map::get_col(piece* p)
{
	return p->get_col();
}

void chess_map::check_move(short r, short c, piece* p)
{
	//if(!(p->check_move(r, c))) return; //TODO: find a better way than these if conditions...
	//if(!(p->check_path(r, c))) return;
	move_piece(r, c, p);
}

void chess_map::check_move(short new_r, short new_c, short old_r, short old_c)
{
	//if (!(p->check_move(new_r, new_c))) return; //TODO: same here
	//if (!(p->check_path(new_r, new_c))) return;
	move_piece(new_r, new_c, old_r, old_c);
}

void chess_map::move_piece(short new_row, short new_col, piece* p)
{
	short old_row = get_row(p);
	short old_col = get_col(p);
	piece_map[new_row][new_col] = p;
	piece_map[old_row][old_col] = new piece(); //encapsulation: should map know the piece's type?
}


void chess_map::move_piece(short new_row, short new_col, short old_row, short old_col)
{
	piece* p = new piece();
	p = piece_map[old_row][old_col];
	piece_map[new_row][new_col] = p;
	piece_map[old_row][old_col] = new piece();
	delete p; //to deallocate temp pointer
}
