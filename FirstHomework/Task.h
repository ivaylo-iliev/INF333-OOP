#pragma once
#include "Menu.h"

class Task
{
private:
	virtual void manual_items();
	virtual void random_items();
	virtual void read_from_file();
protected:
	Menu* menu;
public:
	Task();
	//Task(std::string header_value);
	~Task();
	virtual void initialize_menu(std::string header_value);
	virtual void execute();	
};

