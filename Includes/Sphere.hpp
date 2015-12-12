/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Sphere.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:16:15 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 16:04:46 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "raytracer.h"
# include "Object.hpp"
# include "Point.hpp"
# include <math.h>

class Sphere: public Object
{
	public:
		Sphere(void);
		Sphere(Point center, double radius);
		Sphere(Point center, double radius, Uint32 color);
		Sphere(Point center, double radius, int red, int green, int blue);
		Sphere(Sphere const &src);
		~Sphere(void);

//----- Operators -----
		Sphere			&operator=(Sphere const &src);

//----- Member Functions -----
		double			intersect(Ray const &ray);

//----- Getters & Setters -----
		Point			getCenter(void) const;
		double			getRadius(void) const;
		void			setCenter(Point const &center);
		void			setRadius(double radius);


	private:
		Point			_center;
		double			_radius;
};

#endif
