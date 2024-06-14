#pragma once

#include "Point.h"

class LineByPointAndAngle
{
private:
	Point pt;
	double angle;

public:
	LineByPointAndAngle();
	LineByPointAndAngle(Point pt, double angle);
	~LineByPointAndAngle();

	void setPoint(Point pt);
	void setPoint(double x, double y);
	void setAngle(double angle);
	Point getPoint();
	double getAngle();
	Point calculateIntersectionWithOrdinate();

	friend LineByPointAndAngle operator*(const LineByPointAndAngle& line, double angle);
	friend std::ostream& operator<<(std::ostream& stream, const LineByPointAndAngle& line);
	friend std::istream& operator>>(std::istream& stream, LineByPointAndAngle& line);
};

