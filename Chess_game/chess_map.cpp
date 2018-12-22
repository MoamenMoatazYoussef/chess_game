#include "chess_map.h"

//chess_map::chess_map()
//{}	//TODO: write the constructor here, why not when we initialize chess_map in header?


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

inline void chess_map::init_map()
{
	/*
	piece_map.resize(8);
	for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
	{
		piece_map[row].resize(8);
		std::fill(piece_map[row].begin(), piece_map[row].end(), new piece*);
	}
	*/
}


inline void chess_map::init_black()
{
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());
	piece_map[BLACK_PAWN_ROW].push_back(new pawn());

	piece_map[BLACK_KING_ROW].push_back(new rook());
	piece_map[BLACK_KING_ROW].push_back(new knight());
	piece_map[BLACK_KING_ROW].push_back(new bishop());
	piece_map[BLACK_KING_ROW].push_back(new queen());
	piece_map[BLACK_KING_ROW].push_back(new king());
	piece_map[BLACK_KING_ROW].push_back(new bishop());
	piece_map[BLACK_KING_ROW].push_back(new knight());
	piece_map[BLACK_KING_ROW].push_back(new rook());
}

inline void chess_map::init_white()
{
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());
	piece_map[WHITE_PAWN_ROW].push_back(new pawn());

	piece_map[WHITE_KING_ROW].push_back(new rook());
	piece_map[WHITE_KING_ROW].push_back(new knight());
	piece_map[WHITE_KING_ROW].push_back(new bishop());
	piece_map[WHITE_KING_ROW].push_back(new queen());
	piece_map[WHITE_KING_ROW].push_back(new king());
	piece_map[WHITE_KING_ROW].push_back(new bishop());
	piece_map[WHITE_KING_ROW].push_back(new knight());
	piece_map[WHITE_KING_ROW].push_back(new rook());
}

inline void chess_map::init_middle()
{
	//for (int row = 2; row < BOARD_SIDE_LENGTH - 2; row++)
		//std::fill(piece_map[row].begin(), piece_map[row].end(), new piece*);
		//for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
			//piece_map[row].push_back(new piece());
}