/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Sphere.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:16:15 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 10:45:45 by rvagner             '*+###+*'           */
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
		Sphere(Vector center, double radius);
		Sphere(Vector center, double radius, Color color);
		Sphere(Sphere const &src);
		~Sphere(void);

//----- Operators -----
		Sphere			&operator=(Sphere const &src);

//----- Member Functions -----
		double			intersect(Ray const &ray);

//----- Getters & Setters -----
		double			getRadius(void) const;
		void			setRadius(double radius);


	private:
		double			_radius;
};

#endif
