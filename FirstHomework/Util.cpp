#include "Util.h"
#include <iostream>
#include <fstream>
#include <string>

bool Util::choice_is_valid(int choice)
{
	return (choice > 0 && choice < 26) ? true : false;
}

std::vector<std::string> Util::read_task_definitions()
{
	std::vector<std::string> task_definitions;
	std::fstream data_file;
	data_file.open("TaskDefinitions.txt", std::ios::in);
	std::string line;

	if (data_file.is_open()) {
		while (std::getline(data_file, line))
		{
			std::cout << line << std::endl;
			task_definitions.push_back(line);
		}
		data_file.close();
	}

	return task_definitions;
}
