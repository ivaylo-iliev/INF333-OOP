#pragma once
#include "Point.h"
class PointInSpace : public Point
{
private:
	double z;
		
public:
	PointInSpace();
	PointInSpace(double, double, double);
	~PointInSpace();

	double getZ() const;
	void setZ(double);

	friend std::ostream& operator<<(std::ostream& stream, const PointInSpace& point);
	friend std::istream& operator>>(std::istream& stream, PointInSpace& point);

	PointInSpace operator-();
	PointInSpace& operator++();
	PointInSpace operator++(int);
};

