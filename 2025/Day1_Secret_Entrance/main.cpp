#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
	int current_pos = 50;
	int zero_ticks = 0;

	std::ifstream infile ("input.txt");

	std::string current_action;
	while (infile >> current_action)
	{
		if (current_action.empty ())
			continue;

		int sign = current_action.front() == 'L' ? -1 : 1;
		int value = std::stoi(current_action.substr(1)) * sign;
		current_pos = current_pos + value;
		current_pos = current_pos % 100;

		if (current_pos == 0)
		    ++zero_ticks;
	}
	std::cout << zero_ticks;

	return 0;
}
