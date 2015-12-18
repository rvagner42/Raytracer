/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Camera.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 09:05:10 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 15:03:49 by rvagner             '*+###+*'           */
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
		Camera(Vector p_eye, Vector p_target, Vector v_up, double d, double fov, double ratio);
		virtual ~Camera(void);

//----- Member functions -----
		void		calc_basis(void);
		void		calc_img(void);
		Ray			castRay(int x, int y);

//----- Getters & Setters -----
		Vector		getEye(void) const;
		Vector		getTarget(void) const;
		Vector		getVectorUp(void) const;
		double		getDist(void) const;
		double		getFOV(void) const;
		double		getRatio(void) const;

		void		setEye(Vector const &p_eye);
		void		setTarget(Vector const &p_target);
		void		setVectorUp(Vector const &v_up);
		void		setDist(double d);
		void		setFOV(double fov);
		void		setRatio(double ratio);

	private:
		Vector		_p_eye;
		Vector		_p_target;
		Vector		_v_up;
		double		_d;
		double		_fov;
		double		_ratio;

		Vector		_v_n;
		Vector		_v_u;
		Vector		_v_v;
		double		_pw;
		double		_ph;
		Vector		_p_blc;
};

#endif
