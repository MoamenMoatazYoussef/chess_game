#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

#include "piece.h"

#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "none.h"

#include "common.h"

#define BOARD_SIDE_LENGTH 8
#define BOARD_AREA (BOARD_SIDE_LENGTH*BOARD_SIDE_LENGTH)

#define BLACK_KING_ROW 0
#define BLACK_PAWN_ROW 1
#define WHITE_PAWN_ROW 6
#define WHITE_KING_ROW 7

enum Row{ A, B, C, D, E, F, G };

class chess_map
{
public:
	void init_map();	//TODO: declare these as const so we can use inline for them at cpp
	void init_black();	//However this isn't necessary, they're called only once
	void init_white();

	chess_map() : piece_map(8, std::vector<piece*>(8))
	{
		init_map();
		//unit_test_check_move();
	}

	~chess_map()
	{
		//TODO: deallocate piece_map
	}

	piece* get_piece(short, short);

	void set_piece(short, short, piece*);

	short get_row(piece*);

	short get_col(piece*);

	bool check_move(short, short, piece*);

	bool check_path(short, short, piece*);

	bool can_capture(piece* , piece* ); //TODO: Should I save captured pieces in an array??

	void move_piece(short, short, piece*);

	void move_piece(short, short, short, short); //TODO: remove this because useless, get_piece + move_piece

	void print_map();

	void unit_test_check_move();

	void unit_test_print_result(bool b); //TODO: Only for testing, should be removed after

private:
	std::vector<std::vector<piece*> > piece_map;
	piece* p;
};

/////////////////////////////////// Helper functions /////////////////////////////////

inline void chess_map::print_map() //TODO: move this to cpp
	{
		for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
		{
			for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
			{
				piece* pp = piece_map[row][col];
				pp->print_type();
				std::cout << " ";
			}
			std::cout << std::endl;
		}
	}

