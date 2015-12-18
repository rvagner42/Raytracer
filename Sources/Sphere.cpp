/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Sphere.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:33:41 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 15:13:40 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.hpp"

Sphere::Sphere(void): _p_center(Vector(0.0, 0.0, 0.0)), _radius(5.0)
{
	this->setColor(Color(0.0, 0.0, 0.0));
	this->setKD(0.2);
	this->setKS(0.8);
	this->setPR(0.2);
	this->setN(0.8);
	this->setIOR(0.2);
}

Sphere::Sphere(Vector p_center, double radius): _p_center(p_center), _radius(radius)
{
	this->setColor(Color(0.0, 0.0, 0.0));
	this->setKD(0.2);
	this->setKS(0.8);
	this->setPR(0.2);
	this->setN(0.8);
	this->setIOR(0.2);
}

Sphere::Sphere(Vector p_center, double radius, Color color): _p_center(p_center), _radius(radius)
{
	this->setColor(color);
	this->setKD(0.2);
	this->setKS(0.8);
	this->setPR(0.2);
	this->setN(0.8);
	this->setIOR(0.2);
}

Sphere::Sphere(Vector p_center, double radius, Color color, double kd, double ks,
		double pr, double n, double ior): _p_center(p_center), _radius(radius)
{
	this->setColor(color);
	this->setKD(kd);
	this->setKS(ks);
	this->setPR(pr);
	this->setN(n);
	this->setIOR(ior);
}

Sphere::Sphere(Sphere const &src): _p_center(src.getCenter()), _radius(src.getRadius())
{
	this->setColor(src.getColor());
	this->setKD(src.getKD());
	this->setKS(src.getKS());
	this->setPR(src.getPR());
	this->setN(src.getN());
	this->setIOR(src.getIOR());
}

Sphere::~Sphere(void)
{
	return ;
}

//----- Operators -----

Sphere							&Sphere::operator=(Sphere const &src)
{
	this->setCenter(src.getCenter());
	this->setRadius(src.getRadius());
	this->setColor(src.getColor());
	this->setKD(src.getKD());
	this->setKS(src.getKS());
	this->setPR(src.getPR());
	this->setN(src.getN());
	this->setIOR(src.getIOR());
	return (*this);
}

//----- Member Functions -----

double							Sphere::intersect(Ray const &ray)
{
	Vector		v_to_center = ray.getOrigin() - this->getCenter();

	double		a = ray.getDirection().dotProduct(ray.getDirection());
	double		b = 2 * v_to_center.dotProduct(ray.getDirection());
	double		c = v_to_center.dotProduct(v_to_center) - pow(this->getRadius(), 2);

	double		delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		delta = sqrt(delta);
		double	t1 = (-b - delta) / (2 * a);
		double	t2 = (-b + delta) / (2 * a);
		if (t2 > 0)
		{
			if (t1 < 0)
				return (t2);
			return ((t1 < t2) ? t1 : t2);
		}
		else
		{
			if (t1 > 0)
				return (t1);
			return (-1);
		}
	}
	return (-1);
}

void							Sphere::getNormal(Vector &p_intersect, Vector &v_normal)
{
	v_normal = p_intersect - this->getCenter();
	v_normal.normalize();
}

//----- Getters & Setters -----

Vector							Sphere::getCenter(void) const
{
	return (this->_p_center);
}

double							Sphere::getRadius(void) const
{
	return (this->_radius);
}

void							Sphere::setCenter(Vector p_center)
{
	this->_p_center = p_center;
}

void							Sphere::setRadius(double radius)
{
	this->_radius = radius;
}
