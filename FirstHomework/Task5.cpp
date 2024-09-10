#include "Task5.h"
#include "Util.h"

Task5::Task5(std::string header_value)
{
	this->initialize_menu(header_value);
}

Task5::~Task5()
{
}

void Task5::manual_items()
{
	SimpleFraction fraction = SimpleFraction();
	std::cin >> fraction;
	fraction.checkIsInteger();
	std::cout << fraction << std::endl;
}

void Task5::random_items()
{
	SimpleFraction fraction = SimpleFraction();
	fraction.setNumerator(Util::random_int(1, 100));
	fraction.setDenominator(Util::random_int(1, 100));
	fraction.checkIsInteger();
	std::cout << fraction << std::endl;
}


