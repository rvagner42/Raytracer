/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Process.hpp                                        .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 18:57:49 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 14:09:30 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "raytracer.h"
# include "Pixel.hpp"

class Process
{
	public:
		Process(void);
		Process(char const *win_name);
		virtual ~Process(void);

// ----- Member functions -----
		void			update(void);
		bool			check_ticks(int n);

// ----- Getters & Setters -----
		SDL_Surface		*getScreen(void) const;

	private:
		SDL_Window	*_win;
		SDL_Surface	*_screen;
};

#endif
