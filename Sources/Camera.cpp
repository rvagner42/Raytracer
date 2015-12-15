/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Camera.cpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 09:18:57 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 10:23:13 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"

Camera::Camera(Point ep, Point coi, Vector up, double d, double fov, double ratio):
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
	double		height;
	double		width;
	Point		image_center;
	Vector		n_dist;
	Vector		u_corner;
	Vector		v_corner;

	height = tan(this->getFOV() * 0.5) * this->getDist() * 2;
	width = height * this->getRatio();

	n_dist = this->_n * this->getDist();
	image_center.setX(this->getEyePosition().getX() - n_dist.getX());
	image_center.setY(this->getEyePosition().getY() - n_dist.getY());
	image_center.setZ(this->getEyePosition().getZ() - n_dist.getZ());
	
	u_corner = this->_u * (width * 0.5);
	v_corner = this->_v * (height * 0.5);
	this->_blc.setX(image_center.getX() - u_corner.getX() - v_corner.getY());
	this->_blc.setY(image_center.getY() - u_corner.getY() - v_corner.getY());
	this->_blc.setZ(image_center.getZ() - u_corner.getZ() - v_corner.getY());

	this->_pw = width / X_RES;
	this->_ph = height / Y_RES;
}

Ray				Camera::build_ray(int x, int y)
{
	Ray		ray;
	Point	screen_pixel;
	Vector	u(this->_u * x * this->_pw);
	Vector	v(this->_v * y * this->_ph);

	screen_pixel.setX(this->_blc.getX() + u.getX() + v.getX());
	screen_pixel.setY(this->_blc.getY() + u.getY() + v.getY());
	screen_pixel.setZ(this->_blc.getZ() + u.getZ() + v.getZ());
	ray.setOrigin(this->getEyePosition());
	ray.setDirection(Vector(this->getEyePosition(), screen_pixel));
	return (ray);
}

void			Camera::move(double x, double y, double z)
{
	Point		new_pos(this->getEyePosition());

	new_pos.setX(new_pos.getX() + x);
	new_pos.setY(new_pos.getY() + y);
	new_pos.setZ(new_pos.getZ() + z);

	this->setEyePosition(new_pos);
	this->calc_basis();
}


//----- Getters & Setters -----
Point			Camera::getEyePosition(void) const
{
	return (this->_ep);
}

Point			Camera::getCenterOfInterest(void) const
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

void			Camera::setEyePosition(Point const &ep)
{
	this->_ep = ep;
}

void			Camera::setCenterOfInterest(Point const &coi)
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
