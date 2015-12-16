/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Color.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/15 18:03:49 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 14:42:18 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

Color::Color(void)
{
	this->_r = 25.0;
	this->_g = 25.0;
	this->_b = 25.0;
	this->_k_diff = 1.0;
	this->_k_spec = 0.5;
}

Color::Color(double r, double g, double b)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_k_diff = 1.0;
	this->_k_spec = 0.5;
}

Color::Color(double r, double g, double b, double k_diff, double k_spec)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
	this->_k_diff = k_diff;
	this->_k_spec = k_spec;
}

Color::Color(Color const &src)
{
	this->_r = src.getRed();
	this->_g = src.getGreen();
	this->_b = src.getBlue();
	this->_k_diff = src.getKDiff();
	this->_k_spec = src.getKSpec();
}

Color::~Color(void)
{
	return ;
}

//----- Member functions -----
Uint32						Color::computeFinalColor(double theta) const
{
	double		diffuse = fmax(0.0, fmin(theta, 0.8)) * this->getKDiff();
	double		final_r = this->getRed() * 0.2 + this->getRed() * diffuse;
	double		final_g = this->getGreen() * 0.2 + this->getGreen() * diffuse;
	double		final_b = this->getBlue() * 0.2 + this->getBlue() * diffuse;

	return (65536 * (Uint8)final_r + 256 * (Uint8)final_g + (Uint8)final_b);
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

double						Color::getKDiff(void) const
{
	return (this->_k_diff);
}

double						Color::getKSpec(void) const
{
	return (this->_k_spec);
}
