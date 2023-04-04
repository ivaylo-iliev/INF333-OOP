#include "Menu.h"
#include <sstream>
#include <iostream>
#include <regex>

Menu::Menu()
{
	max_index = 1;
	choice = 0;
}

Menu::~Menu()
{

}

void Menu::add_entry(std::string entryName)
{
	MenuEntry entry;

	entry.setIndex(this->max_index);
	entry.setLabel(entryName);
	
	this->menuEntries.push_back(entry);
	
	max_index++;
}

const std::vector<MenuEntry> &Menu::getEntries() const
{
	return this->menuEntries;
}


std::ostream& operator<<(std::ostream& stream, const Menu& menu)
{
	stream << std::setfill(HEADER_BORDER_CHAR);
	stream << std::setw(MAX_HEADER_WIDTH) << ' ' <<std::endl;
	stream << std::setfill(' ');

	for(std::string headerLine : menu.headerLines)
	{
		stream << std::setw(HEADER_BORDER_WIDTH) << ' ' << headerLine << std::endl;
	}
	
	stream << std::setfill(HEADER_BORDER_CHAR);
	stream << std::setw(MAX_HEADER_WIDTH) << ' ' <<std::endl;

	for (MenuEntry entry : menu.getEntries()) {
		stream << entry << std::endl;
	}
	stream << "Please, make a selection: ";
	return stream;
}

void Menu::set_header(std::string value)
{
	std::vector<std::string> headerTokens;
	std::stringstream headerValue(value);

	std::string token;
	while(getline(headerValue, token, ' '))
	{
		headerTokens.push_back(token);
	}

	std::string line;
	for(int i = 0; i < headerTokens.size(); i++)
	{
		std::string tempToken;
		if(line.size() > 0)
		{
			 tempToken = line + ' ' + headerTokens[i];
		} 
		else 
		{
			tempToken = headerTokens[i];
		}


		if(i == (headerTokens.size() -1)){			
			this->headerLines.push_back(tempToken);
			line = "";
			continue;
		}

		if(tempToken.length() >= MAX_HEADER_LINE_LENGTH)
		{
			this->headerLines.push_back(line);
			line = "";
			
			continue;
		}

		if(tempToken.length() < MAX_HEADER_LINE_LENGTH)
		{
			line = tempToken;
		}		
	}
}

int Menu::get_selection()
{
	std::string line;

	/*if (!std::getline(std::cin, line)) {
		return MENU_FORCE_EXIT;
	}

	if (line.empty()) {
		return MENU_FORCE_EXIT;
	}*/

	return std::stoi(line);	
}

int Menu::get_max_index()
{
	return max_index;
}