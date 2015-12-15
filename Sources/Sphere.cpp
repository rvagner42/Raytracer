/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Sphere.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:33:41 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 17:08:35 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.hpp"

Sphere::Sphere(void): _radius(5.0)
{
	this->setCenter(Vector(0.0, 0.0, 0.0));
	this->setColor(0xFFFFFF);
}

Sphere::Sphere(Vector center, double radius): _radius(radius)
{
	this->setCenter(center);
	this->setColor(0xFFFFFF);
}

Sphere::Sphere(Vector center, double radius, Uint32 color): _radius(radius)
{
	this->setCenter(center);
	this->setColor(color);
}

Sphere::Sphere(Vector center, double radius, int red, int green, int blue): _radius(radius)
{
	this->setCenter(center);
	this->setColor(red, green, blue);
}

Sphere::Sphere(Sphere const &src): _radius(src.getRadius())
{
	this->setCenter(src.getCenter());
	this->setColor(src.getColor());
}

Sphere::~Sphere(void)
{
	return ;
}

//----- Member Functions -----
double							Sphere::intersect(Ray const &ray)
{
	Vector		e_c(this->getCenter(), ray.getOrigin());
	double		a = ray.getDirection().dotProduct(ray.getDirection());
	double		b = 2 * ray.getDirection().dotProduct(e_c);
	double		c = e_c.dotProduct(e_c) - (this->getRadius() * this->getRadius());
	double		delta = (b * b) - 4 * a * c;

	if (delta < 0)
		return (-1);
	else if (delta == 0)
	{
		double t = (a < 0) ? -1 : (-1 * b) / (2 * a);
		return (t);
	}
	else
	{
		double t1 = (a < 0) ? -1 : (-1 * b - sqrt(delta))  / (2 * a);
		double t2 = (a < 0) ? -1 : (-1 * b + sqrt(delta))  / (2 * a);

		if (t1 < 0 && t2 < 0)
			return (-1);
		else if (t1 < 0)
			return (t2);
		else if (t2 < 0)
			return (t1);
		else
			return ((t1 < t2) ? t1 : t2);
	}
}

//----- Getters & Setters -----
double							Sphere::getRadius(void) const
{
	return (this->_radius);
}

void							Sphere::setRadius(double radius)
{
	this->_radius = radius;
}
