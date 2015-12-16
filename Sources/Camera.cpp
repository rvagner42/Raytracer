/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Camera.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 09:18:57 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 15:03:27 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"

Camera::Camera(Vector ep, Vector coi, Vector up, double d, double fov, double ratio):
	_ep(ep), _coi(coi), _up(up), _d(d), _fov(fov), _ratio(ratio)
{
	this->calc_basis();
}

Camera::~Camera(void)
{
	return ;
}

//----- Member functions -----

void			Camera::calc_basis(void)
{
	this->_n = Vector(this->getCenterOfInterest(), this->getEyePosition());
	this->_n.normalize();

	this->_u = this->getVectorUp() * this->_n;
	this->_u.normalize();

	this->_v = this->_n * this->_u;
	this->calc_img();
}

void			Camera::calc_img(void)
{
	double		height = tan(this->getFOV() * 0.5) * this->getDist() * 2;
	double		width = height * this->getRatio();

	Vector		image_center(this->getEyePosition() - (this->_n * this->getDist()));
	
	this->_blc = image_center - (this->_u * (width * 0.5)) - (this->_v * (height * 0.5));

	this->_pw = width / X_RES;
	this->_ph = height / Y_RES;
}

Ray				Camera::build_ray(int x, int y)
{
	Ray		ray;
	Vector	screen_pixel(this->_blc + (this->_u * x * this->_pw) + (this->_v * y * this->_ph));

	ray.setOrigin(this->getEyePosition());
	ray.setDirection(Vector(this->getEyePosition(), screen_pixel));
	return (ray);
}

void			Camera::move(int x, int y)
{
	Vector		new_point(this->getEyePosition());

	new_point.setX(new_point.getX() + x);
	new_point.setY(new_point.getY() + y);
	this->setEyePosition(new_point);
	this->calc_basis();
}

//----- Getters & Setters -----
Vector			Camera::getEyePosition(void) const
{
	return (this->_ep);
}

Vector			Camera::getCenterOfInterest(void) const
{
	return (this->_coi);
}

Vector			Camera::getVectorUp(void) const
{
	return (this->_up);
}

double			Camera::getDist(void) const
{
	return (this->_d);
}

double			Camera::getFOV(void) const
{
	return (this->_fov);
}

double			Camera::getRatio(void) const
{
	return (this->_ratio);
}

void			Camera::setEyePosition(Vector const &ep)
{
	this->_ep = ep;
}

void			Camera::setCenterOfInterest(Vector const &coi)
{
	this->_coi = coi;
}

void			Camera::setVectorUp(Vector const &up)
{
	this->_up = up;
}

void			Camera::setDist(double d)
{
	this->_d = d;
}

void			Camera::setFOV(double fov)
{
	this->_fov = fov;
}

void			Camera::setRatio(double ratio)
{
	this->_ratio = ratio;
}
