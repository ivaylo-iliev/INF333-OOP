#include <iostream>
#include "Task1.h"
#include <cmath>

Task1::Task1()
{
	this->initialize_menu("Task1 Header");
}

Task1::Task1(std::string header_value)
{
	this->initialize_menu(header_value);
}

void Task1::execute()
{
	int choice = 0;
	int max_index = menu->get_max_index() - 1;
	do
	{
		std::cout << *this->menu;
		choice = menu->get_selection();
		std::cout << choice << std::endl;

		if (choice < 1 || choice > max_index) {
			std::cout << "Invalid choice.Please select from the items in the menu.";
			std::cout << std::endl;
		}
		
		if (choice == max_index)
		{
			break;
		}

		switch (choice)
		{
		case 1:
			manual_items();
			break;
		default: break;
		}


	} while ( true );
}

void Task1::manual_items()
{
	std::cin >> c1;
	std::cin >> c2;
	find_intersection_points(c1, c2);
}

void Task1::random_items()
{

}

void Task1::read_from_file()
{

}

void Task1::find_intersection_points(Circle& c1, Circle& c2)
{

}

