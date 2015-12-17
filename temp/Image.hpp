/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Image.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 08:07:10 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/14 08:49:17 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "raytracer.h"

class Image
{
	public:
		Image(int size_x, int size_y, SDL_Surface *screen);
		~Image(void);

//----- Member functions -----
		void			draw(void);

//----- Getters & Setters -----
		void			setPixel(int x, int y, Uint32 color);
		void			setPixel(int x, int y, int red, int green, int blue);

	private:
		int				_size_x;
		int				_size_y;
		Uint32			**_pixels;
		Uint32			*_data;
};

#endif
