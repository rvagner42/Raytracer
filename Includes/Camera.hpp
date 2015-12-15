/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Camera.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 09:05:10 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/14 17:20:21 by rvagner             '*+###+*'           */
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
		Camera(Point e_p, Point c_o_i, Vector up, double d, double fov, double ratio);
		virtual ~Camera(void);

//----- Member functions -----
		void		calc_basis(void);
		void		calc_img(void);
		Ray			build_ray(int x, int y);

		void		move(double h_shift, double v_shift);

//----- Getters & Setters -----
		Point		getEyePosition(void) const;
		Point		getCenterOfInterest(void) const;
		Vector		getVectorUp(void) const;
		double		getDist(void) const;
		double		getFOV(void) const;
		double		getRatio(void) const;

		void		setEyePosition(Point const &e_p);
		void		setCenterOfInterest(Point const &c_o_i);
		void		setVectorUp(Vector const &up);
		void		setDist(double d);
		void		setFOV(double fov);
		void		setRatio(double ratio);

	private:
		Point		_ep;
		Point		_coi;
		Vector		_up;
		double		_d;
		double		_fov;
		double		_ratio;
		double		_radius;

		Vector		_n;
		Vector		_u;
		Vector		_v;
		double		_pw;
		double		_ph;
		Point		_blc;
};

#endif
