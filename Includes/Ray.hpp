/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Ray.hpp                                            .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 19:12:11 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/17 15:17:55 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "raytracer.h"
#include "Vector.hpp"

class Ray
{
	public:
		Ray(void);
		Ray(Vector p_origin, Vector v_direction);
		Ray(Ray const &src);
		virtual ~Ray(void);

//----- Operators -----
		Ray			&operator=(Ray const &src);

//----- Getters & Setters -----
		Vector		getOrigin(void) const;
		Vector		getDirection(void) const;

		void		setOrigin(Vector const &orig);
		void		setDirection(Vector const &dir);
	
	private:
		Vector		_p_origin;
		Vector		_v_direction;
};

#endif
