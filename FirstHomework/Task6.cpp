#include "Task6.h"
#include "Util.h"
#include <cmath>

Task6::Task6(std::string header_value)
{
	this->initialize_menu(header_value);
}

Task6::~Task6()
{
}

void Task6::manual_items()
{
	std::cout << "Enter point's coordinates:" << std::endl;
	std::cin >> point;
	std::cout << point << std::endl;
	std::cout << "The distance from the point to the origin is: " << this->calculate_distance_to_start() << std::endl;
	std::cout << "Symetric point is:" << -point << std::endl;
}

void Task6::random_items()
{
	point.setX(Util::random_double(0, 100));
	point.setY(Util::random_double(0, 100));
	point.setZ(Util::random_double(0, 100));

	std::cout << point << std::endl;
	std::cout << "The distance from the point to the origin is: " << this->calculate_distance_to_start() << std::endl;
	std::cout << "Symetric point is:" << -point << std::endl;
}

double Task6::calculate_distance_to_start()
{
	return std::sqrt(std::pow(this->point.getX(), 2) + std::pow(this->point.getY() , 2) + std::pow(this->point.getZ(), 2));
}
