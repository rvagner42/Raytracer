/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Camera.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 09:05:10 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/17 16:48:45 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

#include "raytracer.h"
#include <cmath>
#include "Ray.hpp"

class Camera
{
	public:
		Camera(Vector p_eye, Vector p_target, Vector v_up, double img_dist,
				double fov, double x_res, double y_res);
		virtual ~Camera(void);

//----- Member functions -----
		void		calcBasis(void);
		Ray			castRay(int x, int y) const;

//----- Getters & Setters -----
		Vector		getEye(void) const;
		Vector		getTarget(void) const;
		Vector		getVectorUp(void) const;
		double		getImgDist(void) const;
		double		getFOV(void) const;
		double		getXRes(void) const;
		double		getYRes(void) const;

		void		setEye(Vector const &e_p);
		void		setTarget(Vector const &c_o_i);
		void		setVectorUp(Vector const &up);
		void		setImgDist(double d);
		void		setFOV(double fov);
		void		setXRes(double x_res);
		void		setYRes(double y_res);

	private:
		Vector		_p_eye;
		Vector		_p_target;
		Vector		_v_up;
		double		_img_dist;
		double		_fov;
		double		_x_res;
		double		_y_res;

		Vector		_v_n;
		Vector		_v_u;
		Vector		_v_v;
		Vector		_p_bottom_left;
		Vector		_v_inc_x;
		Vector		_v_inc_y;
};

#endif
