#include <iostream>
#include <fstream>

#include "Util.h"
#include "Menu.h"
#include "Task.h"
#include "Task1.h"

int main()
{
	Menu* menu = new Menu();
	
	std::string header = "There are 26 tasks available. Details will be displayed on task selection. ";
	header += "Please make selection between 1 and 26. Value of 0 will exit the program.";

	menu->set_header(header);
	std::vector<std::string> task_definitions = Util::read_task_definitions();

	int main_choice = 0;

	do
	{
		std::cout << *menu;
		main_choice = menu->get_selection();
		Task* task = NULL;

		if (main_choice > 0 && main_choice <= 26)
		{
			switch (main_choice)
			{
			case 1:
				task = new Task1(task_definitions[0]);
				task->execute();
				break;
			default:
				break;

			}

			delete task;
			
		} 

		if (main_choice == 0)
		{
			break;
		}
	
	} while (true);

	delete menu;
}