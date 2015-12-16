/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Object.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:04:21 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 10:39:19 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "raytracer.h"
# include "Ray.hpp"
# include "Color.hpp"

class Object
{
	public:
		virtual double intersect(Ray const &ray) = 0;

		Color		getColor(void) const;
		Vector		getCenter(void) const;

		void		setCenter(Vector const &center);
		void		setColor(Color color);

	protected:
		Color		_color;
		Vector		_center;
};

#endif
