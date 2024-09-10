#pragma once
#include <iostream>
#include <iomanip>
#include "Util.h"

class SimpleFraction
{
private:
	int numerator;
	int denominator;
	bool isInteger = false;

public:
	SimpleFraction();
	SimpleFraction(int, int);
	~SimpleFraction();

	void setNumerator(int);
	int getNumerator() const;
	void setDenominator(int);
	int getDenominator() const;
	void setFraction(int, int);
	std::string checkIsInteger();

	friend std::ostream& operator<<(std::ostream& stream, const SimpleFraction& fraction);
	friend std::istream& operator>>(std::istream& stream, SimpleFraction& fraction); 
	friend SimpleFraction operator+(const SimpleFraction& fraction1, const SimpleFraction& fraction2);
};

