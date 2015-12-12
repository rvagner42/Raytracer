/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Ray.cpp                                            .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 11:07:06 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 18:30:48 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Ray.hpp"

Ray::Ray(void)
{
	return ;
}

Ray::Ray(Point origin, Vector direction): _origin(origin), _direction(direction)
{
	return ;
}

Ray::Ray(Ray const &src): _origin(src.getOrigin()), _direction(src.getDirection())
{
	return ;
}

Ray::~Ray(void)
{
	return ;
}

//----- Operators -----
Ray						&Ray::operator=(Ray const &src)
{
	this->setOrigin(src.getOrigin());
	this->setDirection(src.getDirection());
	return (*this);
}

//----- Getters & Setters -----
Point					Ray::getOrigin(void) const
{
	return (this->_origin);
}

Vector					Ray::getDirection(void) const
{
	return (this->_direction);
}

void					Ray::setOrigin(Point const &orig)
{
	this->_origin = orig;
}

void					Ray::setDirection(Vector const &dir)
{
	this->_direction = dir;
	this->_direction.normalize();
}
