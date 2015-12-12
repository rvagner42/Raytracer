/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Point.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 21:39:04 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 10:19:48 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0.0), _y(0.0), _z(0.0)
{
	return ;
}

Point::Point(double x, double y): _x(x), _y(y), _z(0.0)
{
	return ;
}

Point::Point(double x, double y, double z): _x(x), _y(y), _z(z)
{
	return ;
}

Point::Point(Point const &src): _x(src.getX()), _y(src.getY()), _z(src.getZ())
{
	return ;
}

Point::~Point(void)
{
	return ;
}

//----- Operators -----

Point							&Point::operator=(Point const &src)
{
	this->setX(src.getX());
	this->setY(src.getY());
	this->setZ(src.getZ());
	return (*this);
}

//----- Getters & Setters -----

double							Point::getX(void) const
{
	return (this->_x);
}

double							Point::getY(void) const
{
	return (this->_y);
}

double							Point::getZ(void) const
{
	return (this->_z);
}

void							Point::setX(double x)
{
	this->_x = x;
}

void							Point::setY(double y)
{
	this->_y = y;
}

void							Point::setZ(double z)
{
	this->_z = z;
}

std::ostream						&operator<<(std::ostream &o, Point const &point)
{
	o << "x= " << point.getX() << "; y= " << point.getY() << "; z= " << point.getZ();
	return (o);
}
