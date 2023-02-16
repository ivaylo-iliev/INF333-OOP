#include "Task.h"
#include "Menu.h"

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
	this->menu->add_entry("Read from file");
	this->menu->add_entry("Back to main menu.");
}

void Task::execute()
{

}

void Task::manual_items(){}
void Task::random_items(){}
void Task::read_from_file(){}

