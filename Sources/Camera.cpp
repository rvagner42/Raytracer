/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Camera.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 09:18:57 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 15:05:29 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"

Camera::Camera(Vector p_eye, Vector p_target, Vector v_up, double d, double fov, double ratio):
	_p_eye(p_eye), _p_target(p_target), _v_up(v_up), _d(d), _fov(fov), _ratio(ratio)
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
	this->_v_n = Vector(this->getTarget(), this->getEye());
	this->_v_n.normalize();

	this->_v_u = this->getVectorUp() * this->_v_n;
	this->_v_u.normalize();

	this->_v_v = this->_v_n * this->_v_u;
	this->calc_img();
}

void			Camera::calc_img(void)
{
	double		height = tan(this->getFOV() * 0.5) * this->getDist() * 2;
	double		width = height * this->getRatio();

	Vector		p_image_center(this->getEye() - (this->_v_n * this->getDist()));
	
	this->_p_blc = p_image_center - (this->_v_u * (width * 0.5)) - (this->_v_v * (height * 0.5));

	this->_pw = width / X_RES;
	this->_ph = height / Y_RES;
}

Ray				Camera::castRay(int x, int y)
{
	Ray		ray;
	Vector	p_screen_pixel(this->_p_blc + (this->_v_u * x * this->_pw) + (this->_v_v * y * this->_ph));

	ray.setOrigin(this->getEye());
	ray.setDirection(Vector(this->getEye(), p_screen_pixel));
	return (ray);
}

//----- Getters & Setters -----
Vector			Camera::getEye(void) const
{
	return (this->_p_eye);
}

Vector			Camera::getTarget(void) const
{
	return (this->_p_target);
}

Vector			Camera::getVectorUp(void) const
{
	return (this->_v_up);
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

void			Camera::setEye(Vector const &p_eye)
{
	this->_p_eye = p_eye;
}

void			Camera::setTarget(Vector const &p_target)
{
	this->_p_target = p_target;
}

void			Camera::setVectorUp(Vector const &v_up)
{
	this->_v_up = v_up;
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
