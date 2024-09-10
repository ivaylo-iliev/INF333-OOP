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

std::string SimpleFraction::checkIsInteger()
{
	return (this->numerator % this->denominator == 0 ? "True" : "False");
}

std::ostream& operator<<(std::ostream& stream, const SimpleFraction& fraction)
{
	stream << fraction.numerator << '/' << fraction.denominator;	
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

SimpleFraction operator+(const SimpleFraction& fraction1, const SimpleFraction& fraction2)
{
	SimpleFraction result;
	result.numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
	result.denominator = fraction1.denominator * fraction2.denominator;
	int divisor = Util::greatest_common_divisor(result.numerator, result.denominator);
	result.numerator /= divisor;
	result.denominator /= divisor;

	return result;
}
