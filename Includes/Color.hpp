/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Color.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/15 17:18:58 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 14:03:41 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "raytracer.h"

class Color
{
	public:
		Color(void);
		Color(double r, double g, double b);
		Color(double r, double g, double b, double k_diff, double k_spec);
		Color(Color const &src);
		~Color(void);

//----- Member functions -----
		Uint32		computeFinalColor(double theta) const;

//----- Getters & Setters -----
		double		getRed(void) const;
		double		getGreen(void) const;
		double		getBlue(void) const;
		double		getKDiff(void) const;
		double		getKSpec(void) const;

	private:
		double		_r;
		double		_g;
		double		_b;
		double		_k_diff;
		double		_k_spec;
};

#endif
