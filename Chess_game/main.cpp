#include <iostream>
#include <cmath>

#include "chess_map.h"
#include "piece.h"

int main()
{
	std::cout << ceil(-0.7) << std::endl;
	std::cout << ceil(0.7) << std::endl;
	chess_map c;
	c.print_map();
	piece* p = c.get_piece(4, 5);
	std::cout << c.check_path(7, 5, p) << std::endl;
	std::cout << c.check_path(7, 2, p) << std::endl;
	std::cout << c.check_path(4, 2, p) << std::endl;
	std::cout << c.check_path(3, 4, p) << std::endl;
	//c.move_piece(4, 4, 6, 2);
	return 0;
}