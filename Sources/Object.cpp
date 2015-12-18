/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Object.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:12:12 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 08:31:41 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Object.hpp"

//----- Getters & Setters -----

Color				Object::getColor(void) const
{
	return (this->_color);
}

double				Object::getKD(void) const
{
	return (this->_kd);
}

double				Object::getKS(void) const
{
	return (this->_ks);
}

double				Object::getPR(void) const
{
	return (this->_pr);
}

double				Object::getN(void) const
{
	return (this->_n);
}

double				Object::getIOR(void) const
{
	return (this->_ior);
}

void				Object::setColor(Color color)
{
	this->_color = color;
}

void				Object::setKD(double kd)
{
	this->_kd = kd;
}

void				Object::setKS(double ks)
{
	this->_ks = ks;
}

void				Object::setPR(double pr)
{
	this->_pr = pr;
}

void				Object::setN(double n)
{
	this->_n = n;
}

void				Object::setIOR(double ior)
{
	this->_ior = ior;
}
