#include <iostream>
#include "Task1.h"
#include <cmath>

Task1::Task1()
{
	this->initialize_menu("Task1 Header");
}

Task1::Task1(std::string header_value)
{
	this->initialize_menu(header_value);
}

void Task1::execute()
{
	int choice = 0;
	int max_index = menu->get_max_index() - 1;
	do
	{
		std::cout << *this->menu;
		choice = menu->get_selection();
		std::cout << choice << std::endl;

		if (choice < 1 || choice > max_index) {
			std::cout << "Invalid choice.Please select from the items in the menu.";
			std::cout << std::endl;
		}
		
		if (choice == max_index)
		{
			break;
		}

		switch (choice)
		{
		case 1:
			manual_items();
			break;
		default: break;
		}


	} while ( true );
}

void Task1::manual_items()
{
	std::cin >> c1;
	std::cin >> c2;
	calculate();
}

void Task1::random_items()
{

}

void Task1::read_from_file()
{

}

float Task1::calculate_distance_between_centers()
{
	Point center1 = c1.getCenter();
	Point center2 = c2.getCenter();

	float x2x1 = std::pow((center2.getX() - center1.getX()), 2);
	float y2y1 = std::pow((center2.getY() - center1.getY()), 2);
	float distance = std::sqrt(x2x1 + y2y1);
	return distance;
}

void Task1::calculate() {
	float distance = calculate_distance_between_centers();

	if (distance > (c1.getRadius() + c2.getRadius())) 
	{
		std::cout << "The circles are too far apart and do not intersect." << std::endl;
		return;
	}

	if (distance < (c1.getRadius() + c2.getRadius())) 
	{
		std::cout << "One circle is inside the other and do not intersect." << std::endl;
		return;
	}

	if (distance == 0 && c1.getRadius() == c2.getRadius())
	{
		std::cout << "The circles are merged and there are an infinite number of points of intersection." << std::endl;
		return;
	}

	if (distance == c1.getRadius() + c2.getRadius())
	{
		std::cout << "The circles touch and there is a single intersection point." << std::endl;
		return;
	}

	if (distance < c1.getRadius() + c2.getRadius())
	{
		std::cout << "There are two intersection points." << std::endl;
		return;
	}
}