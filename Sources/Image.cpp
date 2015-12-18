/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Image.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 08:18:23 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 10:06:54 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Image.hpp"

Image::Image(int size_x, int size_y, SDL_Surface *screen): _size_x(size_x), _size_y(size_y)
{
	this->_pixels = new Uint32 *[size_x];

	for (int i = 0; i < size_x; i++)
		this->_pixels[i] = new Uint32 [size_y];
	for (int x = 0; x < size_x; x++)
	{
		for (int y = 0; y < size_y; y++)
			this->_pixels[x][y] = 0x000000;
	}

	this->_data = static_cast<Uint32 *>(screen->pixels);
}

Image::~Image(void)
{
	for (int i = 0; i < this->_size_x; i++)
		delete [] this->_pixels[i];
	delete [] this->_pixels;
}

//----- Member functions -----

void					Image::draw(void)
{
	for (int x = 0; x < this->_size_x; x++)
	{
		for (int y = 0; y < this->_size_y; y++)
			this->_data[y * this->_size_x + x] = this->_pixels[x][y];
	}
}

//----- Getters & Setters -----

void					Image::setPixel(int x, int y, Uint32 color)
{
	this->_pixels[x][y] = color;
}

void					Image::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
{
	this->_pixels[x][y] = 65536 * red + 256 * green + blue;
}
