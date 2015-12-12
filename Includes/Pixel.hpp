/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Pixel.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 18:57:02 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/11 18:57:26 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_H
# define PIXEL_H

# include "raytracer.h"

class Pixel
{
	public:
		Pixel(void);
		Pixel(int x, int y, int red, int green, int blue);
		Pixel(int x, int y, Uint32 color);
		Pixel(Pixel const &src);
		virtual ~Pixel(void);

// ----- Operators -----
		Pixel		&operator=(Pixel const &src);

// ----- Member functions -----
		void		draw(SDL_Surface *surface) const;

//----- Getters & Setters -----
		int		getX(void) const;
		int		getY(void) const;
		Uint32		getColor(void) const;

		void		setX(int x);
		void		setY(int y);
		void		setColor(Uint32 color);
		void		setColor(int red, int green, int blue);

	private:
		int		_x;
		int		_y;
		Uint32		_color;
};

#endif
