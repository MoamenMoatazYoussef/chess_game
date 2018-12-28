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

player chess_map::get_player()
{
	return current_player;
}

void chess_map::set_player(player p)
{
	current_player = p;
}

bool chess_map::check_current_player(short r, short c)
{
	return (piece_map[r][c]->get_player() == current_player);
}

bool chess_map::check_move(short r, short c, piece* p)
{
	return p->check_move(r, c);
}

bool chess_map::check_move(short r1, short c1, short r2, short c2)
{
	piece* p = piece_map[r1][c1];
	return p->check_move(r2, c2);
}

bool chess_map::check_path(short r2, short c2, piece* p) //I named them r1, c1 to be similar to the 
{													   //linear equation but in radial coordinates
	short r1 = p->get_row();						   //where theta is angle, r is radial distance
	short c1 = p->get_col();						   //and x, y are cartesian coordinates
													   //X-axis: columns, Y-axis: rows
	if (p->get_piece_type() != piece_type::Knight)
	{ //If it's a knight, then only check and capture.
		short no_of_squares = std::max(abs(r2 - r1), abs(c2 - c1));

		short rad    = sqrt(pow(r2 - r1, 2) + pow(c2 - c1, 2));
		double theta = asin((r2 - r1)/rad);

		short x_increase = round(sin(theta)); //Because x-axis is equivalent to COLUMN change
		short y_increase = round(cos(theta));

		for (short i = 1; i < no_of_squares; i++)
		{
			short x = (r1 + i*x_increase);
			short y = (c1 + i*y_increase);
			if (piece_map[x][y]->get_piece_type() != piece_type::None)
				return false;
		}
	}
	return (can_capture(p, piece_map[r2][c2]));	
}

bool chess_map::check_path(short r1, short c1, short r2, short c2)
{
	piece* p = piece_map[r1][c1];
	return check_path(r2, c2, p);
}

bool chess_map::can_capture(piece* attacking, piece* defending)
{
	std::cout << defending->get_piece_type() << "  " << attacking->get_piece_type() << std::endl;
	return (attacking->get_player() != defending->get_player());
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
	move_piece(new_row, new_col, p); //TODO: Is that a good practice?
	//piece_map[new_row][new_col] = p;
	//piece_map[old_row][old_col] = new piece();
	delete p; //to deallocate temp pointer
}


///////////////////////////////////////////// Helper functions ////////////////////////////////////

void chess_map::unit_test_print_result(bool b) //TODO: Only for testing, should be removed after
{
	std::cout << b << std::endl;
}

void chess_map::unit_test_check_move()
{
	pawn*   p = new pawn(player::black, 3, 3);
	rook*   r = new rook(3, 3);
	knight* n = new knight(3, 3);
	bishop* b = new bishop(3, 3);
	queen*  q = new queen(3, 3);
	king*   k = new king(3, 3);

	/////////////////////////////////////////////////////////////////////// PAWN TESTED AND OK
	//Pawn:
	//-----
	/*
	std::cout << "Pawn test cases" << std::endl;
	std::cout << "---------------" << std::endl; //Correct anster
	//Test cases at r = 3, c = 3:
	// r2 = 4, c2 = 3
	unit_test_print_result(p->check_move(4, 3)); //True
	// r2 = 2, c2 = 3
	unit_test_print_result(p->check_move(2, 3)); //False (No black/white here)
	// r2 = 5, c2 = 3
	unit_test_print_result(p->check_move(5, 3)); //False
	// r2 = 4, c2 = 4
	unit_test_print_result(p->check_move(4, 4)); //False
	*/
	/////////////////////////////////////////////////////////////////////// ROOK TESTED AND OK
	/*
	std::cout << "Rook test cases" << std::endl;
	std::cout << "---------------" << std::endl;
	//Test cases at r,c = 3, 3:
	// r2 = 3, c2 = 6
	unit_test_print_result(r->check_move(3, 6)); //True
	// r2 = 6, c2 = 3
	unit_test_print_result(r->check_move(3, 6)); //True
	// r2 = 3, c2 = 1
	unit_test_print_result(r->check_move(3, 1)); //True
	// r2 = 1, c2 = 3
	unit_test_print_result(r->check_move(1, 3)); //True
	// r2 = 4, c2 = 4
	unit_test_print_result(r->check_move(4, 4)); //False
	// r2 = 2, c2 = 5
	unit_test_print_result(r->check_move(2, 5)); //False 
	*/
	////////////////////////////////////////////////////////////////////// KNIGHT TESTED AND OK
	/*
	std::cout << "Knight test cases" << std::endl;
	std::cout << "-----------------" << std::endl;
	//Test cases at 3, 3:
	// r2 = 5, c2 = 4
	unit_test_print_result(n->check_move(5, 4)); //All are true
	// r2 = 5, c2 = 2	   
	unit_test_print_result(n->check_move(5, 2));
	// r2 = 4, c2 = 5	   
	unit_test_print_result(n->check_move(4, 5));
	// r2 = 4, c2 = 1	   
	unit_test_print_result(n->check_move(4, 1));

	// r2 = 4, c2 = 5	   
	unit_test_print_result(n->check_move(4, 5));
	// r2 = 2, c2 = 5	   
	unit_test_print_result(n->check_move(2, 5));
	// r2 = 5, c2 = 4	   
	unit_test_print_result(n->check_move(5, 4));
	// r2 = 1, c2 = 4	   
	unit_test_print_result(n->check_move(1, 4));

	// r2 = 1, c2 = 4	   
	unit_test_print_result(n->check_move(1, 4));
	// r2 = 1, c2 = 2	   
	unit_test_print_result(n->check_move(1, 2));
	// r2 = 2, c2 = 5	   
	unit_test_print_result(n->check_move(2, 5));
	// r2 = 2, c2 = 1	   
	unit_test_print_result(n->check_move(2, 1));

	// r2 = 5, c2 = 2	   
	unit_test_print_result(n->check_move(5, 2));
	// r2 = 1, c2 = 2	   
	unit_test_print_result(n->check_move(1, 2));
	// r2 = 4, c2 = 1	   
	unit_test_print_result(n->check_move(4, 1));
	// r2 = 2, c2 = 1	   
	unit_test_print_result(n->check_move(2, 1));
	*/
	////////////////////////////////////////////////////////////////////// BISHOP TESTED AND OK
	/*
	std::cout << "Bishop test cases" << std::endl;
	std::cout << "-----------------" << std::endl;
	//Test cases at r,c = 3, 3:
	// r2 = 6, c2 = 6
	unit_test_print_result(b->check_move(6, 6)); //True
	// r2 = 1, c2 = 5
	unit_test_print_result(b->check_move(5, 1)); //True
	// r2 = 5, c2 = 1
	unit_test_print_result(b->check_move(1, 5)); //True
	// r2 = 1, c2 = 1
	unit_test_print_result(b->check_move(1, 1)); //True
	// r2 = 5, c2 = 6
	unit_test_print_result(b->check_move(5, 6)); //False
	// r2 = 3, c2 = 6
	unit_test_print_result(b->check_move(3, 6)); //False
	// r2 = 8, c2 = 8
	unit_test_print_result(b->check_move(8, 8)); //Should be false...
	*/
	////////////////////////////////////////////////////////////////////// QUEEN TESTED AND OK
	/*
	std::cout << "Queen test cases" << std::endl;
	std::cout << "----------------" << std::endl;
	//Test cases at r = 3, c = 3:
	//Both rook and bishop test cases
	// r2 = 3, c2 = 6
	unit_test_print_result(r->check_move(3, 6)); //True
	// r2 = 6, c2 = 3
	unit_test_print_result(r->check_move(3, 6)); //True
	// r2 = 3, c2 = 1
	unit_test_print_result(r->check_move(3, 1)); //True
	// r2 = 1, c2 = 3
	unit_test_print_result(r->check_move(1, 3)); //True
	// r2 = 4, c2 = 4
	unit_test_print_result(r->check_move(4, 4)); //False
	// r2 = 2, c2 = 5
	unit_test_print_result(r->check_move(2, 5)); //False
	std::cout << "Diagonal movement" << std::endl;
	// r2 = 6, c2 = 6
	unit_test_print_result(b->check_move(6, 6)); //True
	// r2 = 1, c2 = 5
	unit_test_print_result(b->check_move(5, 1)); //True
	// r2 = 5, c2 = 1
	unit_test_print_result(b->check_move(1, 5)); //True
	// r2 = 1, c2 = 1
	unit_test_print_result(b->check_move(1, 1)); //True
	// r2 = 5, c2 = 6
	unit_test_print_result(b->check_move(5, 6)); //False
	// r2 = 3, c2 = 6
	unit_test_print_result(b->check_move(3, 6)); //False
	// r2 = 8, c2 = 8
	unit_test_print_result(b->check_move(8, 8)); //Should be false...
	*/
	////////////////////////////////////////////////////////////////////// KING TESTED AND OK
	/*
	std::cout << "King test cases" << std::endl;
	std::cout << "---------------" << std::endl;
	//Test cases at r,c = 3, 3:
	// r2 = 3, c2 = 4
	unit_test_print_result(k->check_move(3, 4)); //All should be true I think...
	// r2 = 4, c2 = 4
	unit_test_print_result(k->check_move(4, 4));
	// r2 = 4, c2 = 3
	unit_test_print_result(k->check_move(4, 3));
	// r2 = 4, c2 = 2
	unit_test_print_result(k->check_move(4, 2));
	// r2 = 3, c2 = 2
	unit_test_print_result(k->check_move(3, 2));
	// r2 = 2, c2 = 2
	unit_test_print_result(k->check_move(2, 2));
	// r2 = 2, c2 = 3
	unit_test_print_result(k->check_move(2, 3));
	// r2 = 2, c2 = 4
	unit_test_print_result(k->check_move(2, 4));
	// r2 = 5, c2 = 4
	unit_test_print_result(k->check_move(5, 4));
	// r2 = 3, c2 = 5
	unit_test_print_result(k->check_move(3, 5));
	*/
	//////////////////////////////////////////////////////////////////////
}