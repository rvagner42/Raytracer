/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Object.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:12:12 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 17:02:40 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

Uint32				Object::getColor(void) const
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

void				Object::setColor(int red, int green, int blue)
{
	this->_color = 65536 * red + 256 * green + blue;
}

void				Object::setColor(Uint32 color)
{
	this->_color = color;
}
