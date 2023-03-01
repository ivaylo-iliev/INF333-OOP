#pragma once
#include <iostream>
#include <vector>
#include "Circle.h"

class Util
{
public:
	static bool choice_is_valid(int choice);
	static std::vector<std::string> read_task_definitions();

	/*
	 * offset - The starting point for the range of random numbers
	 * range - The number of values between first and the last possible random number including the limits
	 * seed - additional value to modify the seed to get more random values on consequtive calls
	 */
	static int random_int(int offset, int range, int seed);
};

