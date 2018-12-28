#pragma once
#include "chess_map.h"
#include "input_screen.h"

class controller
{
public:
	controller();
	~controller();

	bool check_boundary(std::vector<short>);

	void run_iteration();

	void run();

private:
	chess_map _map;
	input_screen _screen;
};