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
