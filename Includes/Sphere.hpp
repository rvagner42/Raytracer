/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Sphere.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:16:15 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 08:42:28 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "raytracer.h"
# include "Object.hpp"
# include <math.h>

class Sphere: public Object
{
	public:
		Sphere(void);
		Sphere(Vector p_center, double radius);
		Sphere(Vector p_center, double radius, Color color);
		Sphere(Vector p_center, double radius, Color color, double kd, double ks,
				double pr, double n, double ior);
		Sphere(Sphere const &src);
		~Sphere(void);

//----- Operators -----
		Sphere			&operator=(Sphere const &src);

//----- Member Functions -----
		double			intersect(Ray const &ray);
		void			getNormal(Vector const &p_intersect, Vector &v_normal);

//----- Getters & Setters -----
		Vector			getCenter(void) const;
		double			getRadius(void) const;

		void			setCenter(Vector p_center);
		void			setRadius(double radius);


	private:
		Vector			_p_center;
		double			_radius;
};

#endif
