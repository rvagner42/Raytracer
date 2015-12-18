/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Camera.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 09:18:57 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 08:15:50 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"

Camera::Camera(Vector p_eye, Vector p_target, Vector v_up, double img_dist,
		double fov, double x_res, double y_res): _p_eye(p_eye), _p_target(p_target),
	_v_up(v_up), _img_dist(img_dist), _fov(fov), _x_res(x_res), y_res(y_res)
{
	this->calcBasis();
}

Camera::~Camera(void)
{
	return ;
}

//----- Member functions -----

void			Camera::calcBasis(void)
{
	this->_v_n = this->getTarget() - this->getEye();
	this->_n.normalize();

	this->_v_u = this->_v_n * this->getVectorUp();
	this->_u.normalize();

	this->_v_v = this->_v_u * this->_v_n;

	double half_width = tan(this->getFOV() * 0.5);
	double ratio = this->getYRes() / this->getXRes();
	double half_height = ratio * half_width;

	this->_p_bottom_left = this->getEye() + (this->_v_n * this->getImgDist())
		- (this->_v_v * half_height) - (this->_v_u * half_width);

	this->_v_inc_x = (this->_v_u * 2 * half_width) / this->getXRes();
	this->_v_inc_y = (this->_v_v * 2 * half_height) / this->getYRes();
}

Ray				Camera::build_ray(int x, int y)
{
	Vector	screen_pixel(this->_p_bottom_left + (this->_v_inc_x * x) + (this->_v_inc_y * y));

	screen_pixel = screen_pixel + (this->_v_inc_x * 0.5) + (this->_v_inc_y * 0.5);

	return (Ray(this->getEye(), screen_pixel - this->getEye()));
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

double			Camera::getImgDist(void) const
{
	return (this->_img_dist);
}

double			Camera::getFOV(void) const
{
	return (this->_fov);
}

double			Camera::getXRes(void) const
{
	return (this->_x_res);
}

double			Camera::getYRes(void) const
{
	return (this->_y_res);
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

void			Camera::setImgDist(double img_dist)
{
	this->_img_dist = img_dist;
}

void			Camera::setFOV(double fov)
{
	this->_fov = fov;
}

void			Camera::setXRes(double x_res)
{
	this->_x_res = x_res;
}

void			Camera::setYRes(double y_res)
{
	this->_y_res = y_res;
}
