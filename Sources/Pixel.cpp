/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Pixel.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 14:13:48 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 14:13:51 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Pixel.hpp"

Pixel::Pixel(void): _x(0), _y(0), _color(0xFFFFFF)
{
	return ;
}

Pixel::Pixel(int x, int y, int red, int green, int blue): _x(x), _y(y), _color(65536 * red + 256 * green + blue)
{
	return ;
}

Pixel::Pixel(int x, int y, Uint32 color): _x(x), _y(y), _color(color)
{
	return ;
}

Pixel::Pixel(Pixel const &src): _x(src.getX()), _y(src.getY()), _color(src.getColor())
{
	return ;
}

Pixel::~Pixel(void)
{
	return ;
}

// ----- Operators -----

Pixel					&Pixel::operator=(Pixel const &src)
{
	this->setX(src.getX());
	this->setY(src.getY());
	this->setColor(src.getColor());
	return (*this);
}

// ----- Member functions -----

void					Pixel::draw(SDL_Surface *surface) const
{
	Uint32				*data;

	data = static_cast<Uint32 *>(surface->pixels);
	if (this->getX() < 0 || this->getX() > W || this->getY() < 0 || this->getY() > H)
		return ;
	data[this->getY() * surface->w + this->getX()] = this->getColor();
}

// ----- Getters & Setters -----

int					Pixel::getX(void) const
{
	return (this->_x);
}

int					Pixel::getY(void) const
{
	return (this->_y);
}

Uint32					Pixel::getColor(void) const
{
	return (this->_color);
}

void					Pixel::setX(int x)
{
	this->_x = x;
}

void					Pixel::setY(int y)
{
	this->_y = y;
}

void					Pixel::setColor(Uint32 color)
{
	this->_color = color;
}

void					Pixel::setColor(int red, int green, int blue)
{
	this->_color = 65536 * red + 256 * green + blue;
}
