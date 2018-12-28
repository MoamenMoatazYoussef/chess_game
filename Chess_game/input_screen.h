#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>

class input_screen
{
public:
	input_screen();
	~input_screen();

	std::string get_input()
	{
		std::string input;
		std::cout << "Your move! Enter the input in the form: A1 to B1" << std::endl;
		std::getline(std::cin, input);
	}

	void parse_string_by_delimiter(std::string s, std::string d, std::vector<std::string> output)
	{
		size_t pos = 0;
		std::string token;
		while ((pos = s.find(d)) != std::string::npos) {
			token = s.substr(0, pos);
			output.push_back(token);
			s.erase(0, pos + d.length());
		}
	}

	std::vector<std::pair<short, short> > get_parse_send()
	{
		std::string input = get_input();
		std::vector<std::string> input_split;

		parse_string_by_delimiter(input, " ", input_split);

		short old_row = row_map[input_split[0].substr(0, 1)];
		short old_col = std::stoi(input_split[0].substr(1, 1));

		short new_row = row_map[input_split[2].substr(0, 1)];
		short new_col = std::stoi(input_split[2].substr(1, 1));

		std::pair<short, short> old_rc(old_row, old_col);
		std::pair<short, short> new_rc(new_row, new_col);
		std::vector<std::pair<short, short> > final_move({ old_rc, new_rc });

		return final_move;
	}


private:
	std::map<std::string, short> row_map;

};

