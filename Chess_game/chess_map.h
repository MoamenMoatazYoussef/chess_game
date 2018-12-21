#pragma once

#include <vector>
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

#define BLACK_KING_ROW 0
#define BLACK_PAWN_ROW 1
#define WHITE_PAWN_ROW 6
#define WHITE_KING_ROW 7

enum Row{ A, B, C, D, E, F, G };

class chess_map
{
public:
	chess_map();

	~chess_map()
	{
		// Check deallocation of memory, lots of pointers
	}

	void init_black();
	void init_white();

	piece* get_piece(short, short);

	short get_row(piece*);

	short get_col(piece*);

	void set_piece(short, short , piece*);

	void move_piece(short, short, piece*);

	void print_map()
	{
		for (int row = 0; row < BOARD_SIDE_LENGTH; row++)
			for (int col = 0; col < BOARD_SIDE_LENGTH; col++)
			{
				piece* pp = piece_map[row][col];
				pp->print_type();
				std::cout << " ";
				if (col % 10 == 0)
					std::cout << std::endl;
			}
	}

private:
	std::vector<std::vector<piece*> > piece_map;
	// Item **m = new Item*[ n * n ];
	// if you want to access position 1, 2, and n = 5, then:
	// pos = (1 * 5) + 2;
	// Item * it = m[pos];
};