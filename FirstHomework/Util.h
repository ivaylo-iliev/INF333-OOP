#pragma once
#include <iostream>
#include <vector>

class Util
{
public:
	static bool choice_is_valid(int choice);
	static std::vector<std::string> read_task_definitions();
};

