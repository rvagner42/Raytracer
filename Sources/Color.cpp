/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Color.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/15 18:03:49 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 15:32:23 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

Color::Color(void): _r(0.0), _g(0.0), _b(0.0)
{
	return ;
}

Color::Color(double r, double g, double b): _r(r), _g(g), _b(b)
{
	this->_autoClamp();
	return ;
}

Color::Color(Color const &src): _r(src.getRed()), _g(src.getGreen()), _b(src.getBlue())
{
	this->_autoClamp();
	return ;
}

Color::~Color(void)
{
	return ;
}

//----- Operators -----

Color						&Color::operator=(Color const &src)
{
	this->setRed(src.getRed());
	this->setGreen(src.getGreen());
	this->setBlue(src.getBlue());
	return (*this);
}

Color						Color::operator+(Color const &rhs)
{
	return (Color(
				this->getRed() + rhs.getRed(),
				this->getGreen() + rhs.getGreen(),
				this->getBlue() + rhs.getBlue()
				));
}

Color						Color::operator-(Color const &rhs)
{
	return (Color(
				this->getRed() - rhs.getRed(),
				this->getGreen() - rhs.getGreen(),
				this->getBlue() - rhs.getBlue()
				));
}

Color						Color::operator*(Color const &rhs)
{
	return (Color(
				this->getRed() * rhs.getRed(),
				this->getGreen() * rhs.getGreen(),
				this->getBlue() * rhs.getBlue()
				));
}

Color						Color::operator*(double const &rhs)
{
	return (Color(
				this->getRed() * rhs,
				this->getGreen() * rhs,
				this->getBlue() * rhs
				));
}

//----- Member functions -----
Uint32						Color::computeColor(void) const
{
	Uint8	red   = static_cast<Uint8>(this->getRed() * 255.0);
	Uint8	green = static_cast<Uint8>(this->getGreen() * 255.0);
	Uint8	blue  = static_cast<Uint8>(this->getBlue() * 255.0);

	Uint32 color = 65536 * red + 256 * green + blue;
	return (color);
}

//----- Getters & Setters -----

double						Color::getRed(void) const
{
	return (this->_r);
}

double						Color::getGreen(void) const
{
	return (this->_g);
}

double						Color::getBlue(void) const
{
	return (this->_b);
}

void						Color::setRed(double red)
{
	this->_r = red;
	this->_autoClamp();
}

void						Color::setGreen(double green)
{
	this->_g = green;
	this->_autoClamp();
}

void						Color::setBlue(double blue)
{
	this->_b = blue;
	this->_autoClamp();
}

//----- Private -----

void						Color::_autoClamp(void)
{
	this->_r = fmin(this->getRed(), 1.0);
	this->_g = fmin(this->getGreen(), 1.0);
	this->_b = fmin(this->getBlue(), 1.0);
}
