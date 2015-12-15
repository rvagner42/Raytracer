/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Object.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:04:21 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 17:02:27 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "raytracer.h"
# include "Ray.hpp"

class Object
{
	public:
		virtual double intersect(Ray const &ray) = 0;

		Uint32		getColor(void) const;
		Vector		getCenter(void) const;

		void		setCenter(Vector const &center);
		void		setColor(int red, int green, int blue);
		void		setColor(Uint32 color);

	protected:
		Uint32		_color;
		Vector		_center;
};

#endif
