#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

#define OFFSET_FOR_INDEX 1

class input_screen
{
public:
	input_screen();
	~input_screen();

	std::string get_input();

	void parse_string_by_delimiter(std::string, std::string, std::vector<std::string>);

	std::vector<short> get_parse_send();

	void input_error(short);


private:
	std::map<std::string, short> row_map;

};