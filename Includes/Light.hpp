/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Light.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/18 09:37:14 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 09:54:23 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "raytracer.h"
# include "Color.hpp"
# include "Vector.hpp"

class Light
{
	public:
		Light(void);
		Light(Vector const &p_pos);
		Light(Vector const &p_pos, Color const &color);
		Light(Light const &src);
		virtual ~Light(void);

//----- Operators -----
		Light		&operator=(Light const &src);

//----- Getters & Setters -----
		Vector		getPos(void) const;
		Color		getColor(void) const;

		void		setPos(Vector const &p_pos);
		void		setColor(Color const &color);
	
	private:
		Vector		_p_pos;
		Color		_color;
};

#endif
