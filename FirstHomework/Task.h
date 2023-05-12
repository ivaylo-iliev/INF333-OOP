#pragma once
#include "Menu.h"

class Task
{
private:
	virtual void manual_items();
	virtual void random_items();

protected:
	Menu* menu;

public:
	Task();
	~Task();
	virtual void initialize_menu(std::string header_value);
	virtual void execute();	
};

