/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Ray.cpp                                            .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 11:07:06 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 11:29:23 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Ray.hpp"

Ray::Ray(void)
{
	return ;
}

Ray::Ray(Vector p_origin, Vector v_direction): _p_origin(p_origin), _v_direction(v_direction)
{
	return ;
}

Ray::Ray(Ray const &src): _p_origin(src.getOrigin()), _v_direction(src.getDirection())
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
Vector					Ray::getOrigin(void) const
{
	return (this->_p_origin);
}

Vector					Ray::getDirection(void) const
{
	return (this->_v_direction);
}

void					Ray::setOrigin(Vector const &p_origin)
{
	this->_p_origin = p_origin;
}

void					Ray::setDirection(Vector const &v_direction)
{
	this->_v_direction = v_direction;
	this->_v_direction.normalize();
}
