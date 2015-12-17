/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Color.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/15 18:03:49 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/17 15:15:49 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

Color::Color(void): _r(0.0), _g(0.0), _b(0.0)
{
	return ;
}

Color::Color(int r, int g, int b): _r(r / 255.0), _g(g / 255.0), _b(b / 255.0)
{
	this->_autoClamp();
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
				this->getRed() * rsh,
				this->getGreen() * rhs,
				this->getBlue() * rhs
				));
}

//----- Member functions -----
Uint32						Color::computeFinalColor(void) const
{
	Uint8	red   = static_cast<Uint8>(this->getRed() * 255);
	Uint8	green = static_cast<Uint8>(this->getGreen() * 255);
	Uint8	blue  = static_cast<Uint8>(this->getBlue() * 255);
	return (65536 * red + 256 * green + blue);
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

void						Color::autoClamp(void)
{
	this->_r = fmax(0.0, fmin(this->getRed(), 1.0));
	this->_g = fmax(0.0, fmin(this->getGreen(), 1.0));
	this->_b = fmax(0.0, fmin(this->getBlue(), 1.0));
}
