#include "controller.h"

controller::controller()
{
}

controller::~controller()
{
}

bool controller::check_boundary(std::vector<short> move)
{
	for (short i = move.size() / 2; i < move.size(); i++) //Divided by 2 because we only check on the NEW position
	{
		bool within_boundaries = (move[i] <= 7) && (move[i] >= 0);
		if (!within_boundaries)
		{
			_screen.input_error(1);
			return false;
		}
	}
	return true;
}

void controller::run_iteration()
{
	std::vector<short> move = _screen.get_parse_send();		//Step 1: get input

	if (move.size() > 4)	//Check that we have both moves
	{
		_screen.input_error(0);
		return;
	}

	if (!check_boundary(move))								//Step 2: check that requested moves are within boundaries
	{
		_screen.input_error(1);
		return;
	}

	if (!_map.check_current_player(move[0], move[1]))	//Step 3: check that the player is moving a piece that belongs to them
	{
		_screen.input_error(2);
		return;
	}

	if (!_map.check_move(move[0], move[1], move[2], move[3]))
	{
		_screen.input_error(3);
		return;
	}

	if (!_map.check_path(move[0], move[1], move[2], move[3]))
	{
		_screen.input_error(3);
		return;
	}

	_map.move_piece(move[0], move[1], move[2], move[3]);
	_map.print_map();
}

void controller::run()
{
	;//while loop containing the run iteration

}