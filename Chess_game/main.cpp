#include <iostream>

#include "chess_map.h"
#include "piece.h"

int main()
{
	chess_map c;
	c.print_map();
	//c.move_piece(4, 4, 6, 2);
	c.print_map();
	return 0;
}