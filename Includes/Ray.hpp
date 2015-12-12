/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Ray.hpp                                            .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 19:12:11 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 17:23:32 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "raytracer.h"
#include "Point.hpp"
#include "Vector.hpp"

class Ray
{
	public:
		Ray(void);
		Ray(Point origin, Vector direction);
		Ray(Ray const &src);
		virtual ~Ray(void);

//----- Operators -----
		Ray			&operator=(Ray const &src);

//----- Getters & Setters -----
		Point		getOrigin(void) const;
		Vector		getDirection(void) const;

		void		setOrigin(Point const &orig);
		void		setDirection(Vector const &dir);
	
	private:
		Point		_origin;
		Vector		_direction;
};

#endif
