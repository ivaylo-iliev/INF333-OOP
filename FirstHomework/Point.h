#pragma once
#include <iostream>

class Point
{
	int x;
	int y;
public:
	Point();
	Point(int, int);
	~Point();

	void setX(int);
	void setY(int);
	const int getX() const;
	const int getY() const;

	friend std::ostream& operator<<(std::ostream& stream, const Point& point);
	friend std::istream& operator>>(std::istream& stream, Point& point);
};


