#include "MenuEntry.h"

void MenuEntry::setIndex(int index)
{
	this->index = index;
}

const int& MenuEntry::getIndex() const
{
	return this->index;
}

void MenuEntry::setLabel(std::string label)
{
	this->label = label;
}


const std::string& MenuEntry::getLabel() const
{
	return this->label;
}

std::ostream& operator<<(std::ostream& stream, const MenuEntry& entry)
{
	stream << std::setfill(' ');
	stream << std::setw(INDEX_WIDTH) << entry.getIndex() << POINT;
	stream << std::setw(SEPARATOR_WIDTH) << SEPARATOR;
	stream << entry.getLabel();

	return stream;
}

