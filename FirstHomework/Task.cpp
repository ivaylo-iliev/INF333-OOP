#include "Task.h"
#include "Menu.h"
#include <iostream>

Task::Task()
{
	this->menu = new Menu();
}

Task::~Task()
{
	delete menu;
}

void Task::initialize_menu(std::string header_value)
{
	this->menu->set_header(header_value);
	this->menu->add_entry("Manual values.");
	this->menu->add_entry("Random values.");
	this->menu->add_entry("Back to main menu.");
}

void Task::execute()
{
	int choice = 0;
	int max_index = menu->get_max_index() - 1;
	do
	{
		std::cout << *this->menu;
		std::cin >> choice;


		if (choice > 0 && choice < max_index)
		{
			switch (choice)
			{
			case 1:
				manual_items();
				break;
			case 2:
				random_items();
			default: break;
			}
		}
		else
		{
			break;
		}


	} while (true);
}
void Task::manual_items(){}
void Task::random_items(){}

