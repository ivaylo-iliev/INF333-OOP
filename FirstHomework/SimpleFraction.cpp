#include "SimpleFraction.h"

SimpleFraction::SimpleFraction()
{
	numerator = 1;
	denominator = 1;
}

SimpleFraction::SimpleFraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	this->checkIsInteger();
}

SimpleFraction::~SimpleFraction()
{
}

void SimpleFraction::setNumerator(int value)
{
	this->numerator = value;
}

int SimpleFraction::getNumerator() const
{
	return numerator;
}

void SimpleFraction::setDenominator(int value)
{
	this->denominator = value;
}

int SimpleFraction::getDenominator() const
{
	return denominator;
}

void SimpleFraction::setFraction(int numerator, int denominator)
{
	this->setNumerator(numerator);
	this->setDenominator(denominator);
}

void SimpleFraction::checkIsInteger()
{
	this->isInteger =  (this->numerator % this->denominator == 0 ? true : false);
}

std::ostream& operator<<(std::ostream& stream, const SimpleFraction& fraction)
{
	stream << "The numerator is: " << fraction.getNumerator() << ". ";
	stream << "The denominator is:  " << fraction.getDenominator() << ". ";
	stream << (fraction.isInteger ? "Fraction is integer." : "Fraction is not integer.") << std::endl;

	return stream;
}

std::istream& operator>>(std::istream& stream, SimpleFraction& fraction)
{
	int numerator = 0, denominator = 0;
	int firstAttempt = true;
	do {
		std::cout << "Enter numerator: : ";
		if (numerator == 0 && !firstAttempt) {
			std::cout << "Value cannot be 0. Enter numerator: ";
		}
		stream >> numerator;
		firstAttempt = false;
	} while (numerator == 0);

	fraction.setNumerator(numerator);
	firstAttempt = true;

	do {
		std::cout << "Enter denominator: ";
		if (denominator == 0 && !firstAttempt) {
			std::cout << "Value cannot be 0. Enter denominator: ";
		}
		stream >> denominator;
		firstAttempt = false;
	} while (denominator == 0);

	fraction.setDenominator(denominator);

	return stream;
}
