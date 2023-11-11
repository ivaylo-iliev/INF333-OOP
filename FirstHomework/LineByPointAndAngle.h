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
	LineByPointAndAngle rotateLine(Point p, double rotationAngleInDegrees);

	LineByPointAndAngle operator*(double rotationAngle);
};

