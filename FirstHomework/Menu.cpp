#include "Menu.h"
#include <sstream>
#include <iostream>
#include <regex>
#include "Util.h"

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
	stream << std::endl;
	stream << std::setfill(HEADER_BORDER_CHAR);
	stream << std::setw(MAX_HEADER_WIDTH) << ' ' <<std::endl;
	stream << std::setfill(' ');

	for(std::string headerLine : menu.headerLines)
	{
		stream << std::setw(HEADER_BORDER_WIDTH) << ' ' << headerLine << std::endl;
	}
	
	stream << std::setfill(HEADER_BORDER_CHAR);
	stream << std::setw(MAX_HEADER_WIDTH) << ' ' <<std::endl << std::endl;

	for (MenuEntry entry : menu.getEntries()) {
		stream << entry << std::endl;
	}
	//stream << std::endl;
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

	std::vector<std::string> lineTokens;
	int current_line_size = 0;
	for(int i = 0; i < headerTokens.size(); i++)
	{
		lineTokens.push_back(headerTokens[i]);
		current_line_size += headerTokens[i].length();

		if ((i  < headerTokens.size() -1 && current_line_size + headerTokens[i+1].size() > MAX_HEADER_LINE_LENGTH) || i == headerTokens.size() - 1) {
			this->headerLines.push_back(Util::string_join(lineTokens, " "));
			lineTokens.clear();
			current_line_size = 0;
		}		
	}
}

int Menu::get_max_index()
{
	return max_index;
}