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
	SimpleFraction fraction1 = SimpleFraction();
	std::cin >> fraction1;

	SimpleFraction fraction2 = SimpleFraction();
	std::cin >> fraction2;

	std::cout << "First fraction: " << fraction1 << ", IsInteger: " << fraction1.checkIsInteger() << std::endl;
	std::cout << "Second fraction: " << fraction2 << ", IsInteger: " << fraction2.checkIsInteger() << std::endl;
	
	SimpleFraction fractionSumResult = fraction1 + fraction2;
	std::cout << "Fraction addition result: " << fractionSumResult << ", IsInteger: " << fractionSumResult.checkIsInteger() << std::endl;
}

void Task5::random_items()
{
	SimpleFraction fraction1 = SimpleFraction();
	fraction1.setNumerator(Util::random_int(1, 100));
	fraction1.setDenominator(Util::random_int(1, 100));
	std::cout << "First fraction: " << fraction1 << ", IsInteger: " << fraction1.checkIsInteger() << std::endl;

	SimpleFraction fraction2 = SimpleFraction();
	fraction2.setNumerator(Util::random_int(1, 100));
	fraction2.setDenominator(Util::random_int(1, 100));
	std::cout << "Second fraction: " << fraction2 << ", IsInteger: " << fraction2.checkIsInteger() << std::endl;

	SimpleFraction fractionSumResult = fraction1 + fraction2;
	std::cout << "Fraction addition result: " << fractionSumResult << ", IsInteger: " << fractionSumResult.checkIsInteger() << std::endl;
}


