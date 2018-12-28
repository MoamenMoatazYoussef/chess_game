#include "input_screen.h"


input_screen::input_screen()
{
	row_map.insert(std::pair<std::string, short>("A", 0));
	row_map.insert(std::pair<std::string, short>("B", 1));
	row_map.insert(std::pair<std::string, short>("C", 2));
	row_map.insert(std::pair<std::string, short>("D", 3));
	row_map.insert(std::pair<std::string, short>("E", 4));
	row_map.insert(std::pair<std::string, short>("F", 5));
	row_map.insert(std::pair<std::string, short>("G", 6));
	row_map.insert(std::pair<std::string, short>("H", 7));
}


input_screen::~input_screen()
{
}

std::string input_screen::get_input()
{
	std::string input;
	std::cout << "Your move! Enter the input in the form: A1 to B1" << std::endl;
	std::getline(std::cin, input);
	return input;
}

void input_screen::parse_string_by_delimiter(std::string s, std::string d, std::vector<std::string> output)
{
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(d)) != std::string::npos) {
		token = s.substr(0, pos);
		output.push_back(token);
		s.erase(0, pos + d.length());
	}
}

std::vector<short> input_screen::get_parse_send()
{
	std::string input = get_input();
	std::vector<std::string> input_split;

	parse_string_by_delimiter(input, " ", input_split);

	short old_row = row_map[input_split[0].substr(0, 1)];
	short old_col = std::stoi(input_split[0].substr(1, 1)) - OFFSET_FOR_INDEX;

	short new_row = row_map[input_split[2].substr(0, 1)];
	short new_col = std::stoi(input_split[2].substr(1, 1)) - OFFSET_FOR_INDEX;

	std::vector<short> final_move({ old_row, old_col, new_row, new_col });

	return final_move;
}

void input_screen::input_error(short e)
{
	switch (e)
	{
	case(0) :
		std::cout << "ERROR: a parameter is missing, please input TWO rows and TWO columns: r1, c1, r2, c2." << std::endl;
		break;
	case(1) :
		std::cout << "ERROR: row/col is out of bounds." << std::endl;
		break;
	case(2) :
		std::cout << "ERROR: trying to move other player's piece" << std::endl;
		break;
	}
}
