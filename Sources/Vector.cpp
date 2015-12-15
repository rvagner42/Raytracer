/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Vector.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 21:47:57 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 17:12:38 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector(void): _x(0.0), _y(0.0), _z(0.0)
{
	return ;
}

Vector::Vector(double x, double y, double z): _x(x), _y(y), _z(z)
{
	return ;
}

Vector::Vector(Vector const &orig, Vector const &dest): _x(dest.getX() - orig.getX()), _y(dest.getY() - orig.getY()), _z(dest.getZ() - orig.getZ())
{
	return ;
}

Vector::Vector(Vector const &src): _x(src.getX()), _y(src.getY()), _z(src.getZ())
{
	return ;
}

Vector::~Vector(void)
{
	return ;
}

//----- Operators -----

Vector								&Vector::operator=(Vector const &src)
{
	this->setX(src.getX());
	this->setY(src.getY());
	this->setZ(src.getZ());
	return (*this);
}

Vector								Vector::operator+(Vector const &rhs)
{
	return (Vector(
					this->getX() + rhs.getX(),
					this->getY() + rhs.getY(),
					this->getZ() + rhs.getZ()));
}

Vector								Vector::operator-(Vector const &rhs)
{
	return (Vector(
					this->getX() - rhs.getX(),
					this->getY() - rhs.getY(),
					this->getZ() - rhs.getZ()));
}

Vector								Vector::operator*(Vector const &rhs)
{
	return (Vector(
					this->getY() * rhs.getZ() - this->getZ() * rhs.getY(),
					this->getZ() * rhs.getX() - this->getX() * rhs.getZ(),
					this->getX() * rhs.getY() - this->getY() * rhs.getX()));
}

Vector								Vector::operator*(double const &rhs)
{
	return (Vector(
					this->getX() * rhs,
					this->getY() * rhs,
					this->getZ() * rhs));
}

//----- Getters & Setters -----

double								Vector::getX(void) const
{
	return (this->_x);
}

double								Vector::getY(void) const
{
	return (this->_y);
}

double								Vector::getZ(void) const
{
	return (this->_z);
}

void								Vector::setX(double x)
{
	this->_x = x;
}

void								Vector::setY(double y)
{
	this->_y = y;
}

void								Vector::setZ(double z)
{
	this->_z = z;
}

//----- Others -----

double								Vector::magnitude(void) const
{
	return (sqrt(this->getX() * this->getX()
				+ this->getY() * this->getY()
				+ this->getZ() * this->getZ()));
}

void								Vector::normalize(void)
{
	if (this->getX() <= 1 && this->getY() <= 1 && this->getZ() <= 1)
		return ;

	double magn = this->magnitude();
	double len = (magn != 0) ? 1 / magn : 0;

	this->setX(this->getX() * len);
	this->setY(this->getY() * len);
	this->setZ(this->getZ() * len);
}

double								Vector::dotProduct(Vector const &rhs) const
{
		return (this->getX() * rhs.getX()
				+ this->getY() * rhs.getY()
				+ this->getZ() * rhs.getZ());
}

std::ostream						&operator<<(std::ostream &o, Vector const &vector)
{
	o << "x= " << vector.getX() << "; y= " << vector.getY() << "; z= " << vector.getZ();
	return (o);
}
