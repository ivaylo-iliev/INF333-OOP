#include <iostream>
#include <fstream>

#include "Util.h"
#include "Menu.h"
#include "Task.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"
#include "Task5.h"

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
		Task* task = NULL;

		std::cout << *menu;
		std::cin >> main_choice;
		

		if (std::cin.fail() || main_choice < 0 || main_choice > 26)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please select value between 1 and " << 26 << ". 0 exits the program." << std::endl;
		} 
		else if (main_choice > 0 && main_choice <= 26)
		{
			switch (main_choice)
			{
			case 1:
				task = new Task1(task_definitions[0]);
				task->execute();
				continue;
			case 2:
				task = new Task2(task_definitions[1]);
				task->execute();
				continue;
			case 3:
				task = new Task3(task_definitions[2]);
				task->execute();
				continue;
			case 4:
				task = new Task4(task_definitions[3]);
				task->execute();
				continue;
			case 5:
				task = new Task5(task_definitions[4]);
				task->execute();
				continue;
			default:
				break;

			}

			delete task;
		} 

		if (main_choice == 0)
		{
			std::cout << 'Bye!' << std::endl;
			break;
		}
	
	} while (true);

	delete menu;
}