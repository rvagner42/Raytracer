/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Light.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/18 09:45:22 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 09:54:12 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Light.hpp"

Light::Light(void): _p_pos(Vector(0.0, 0.0, 0.0)), _color(Color(1.0, 1.0, 1.0))
{
	return ;
}

Light::Light(Vector const &p_pos): _p_pos(p_pos), _color(Color(1.0, 1.0, 1.0))
{
	return ;
}

Light::Light(Vector const &p_pos, Color const &color): _p_pos(p_pos), _color(color)
{
	return ;
}

Light::Light(Light const &src): _p_pos(src.getPos()), _color(src.getColor())
{
	return ;
}

Light::~Light(void)
{
	return ;
}

//----- Operators -----

Light						&Light::operator=(Light const &src)
{
	this->setPos(src.getPos());
	this->setColor(src.getColor());
	return (*this);
}

//----- Getters & Setters -----

Vector						Light::getPos(void) const
{
	return (this->_p_pos);
}

Color						Light::getColor(void) const
{
	return (this->_color);
}

void						Light::setPos(Vector const &p_pos)
{
	this->_p_pos = p_pos;
}

void						Light::setColor(Color const &color)
{
	this->_color = color;
}
