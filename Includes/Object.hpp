/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Object.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:04:21 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 15:31:35 by rvagner             '*+###+*'           */
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
		void		setColor(int red, int green, int blue);
		void		setColor(Uint32 color);

	protected:
		Uint32		_color;
};

#endif
