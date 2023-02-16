#pragma once
#include <string>
#include <iomanip>

constexpr int INDEX_WIDTH = 3;
constexpr int SEPARATOR_WIDTH = 1;
constexpr char SEPARATOR = ' ';
constexpr char POINT = '.';

class MenuEntry
{
private:
	int index = 0;
	std::string label;

public:
	void setIndex(int);
	const int& getIndex() const;
	void setLabel(std::string);
	const std::string& getLabel() const;
};

std::ostream& operator<<(std::ostream& stream, const MenuEntry& entry);

