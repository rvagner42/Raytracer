/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Object.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:12:12 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 10:49:09 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Color				Object::getColor(void) const
{
	return (this->_color);
}

Vector				Object::getCenter(void) const
{
	return (this->_center);
}

void				Object::setCenter(Vector const &center)
{
	this->_center = center;
}

void				Object::setColor(Color color)
{
	this->_color = color;
}
