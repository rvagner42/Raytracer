/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Color.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/15 17:18:58 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/17 14:52:19 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "raytracer.h"

class Color
{
	public:
		Color(void);
		Color(int r, int g, int b);
		Color(double r, double g, double b);
		Color(Color const &src);
		virtual ~Color(void);

//----- Operators -----
		Color					&operator=(Color const &src);
		Color					operator+(Color const &rhs);
		Color					operator-(Color const &rhs);
		Color					operator*(Color const &rhs);
		Color					operator*(double const &rhs);

//----- Member functions -----
		Uint32					computeColor(void) const;

//----- Getters & Setters -----
		double					getRed(void) const;
		double					getGreen(void) const;
		double					getBlue(void) const;

		void					setRed(double red);
		void					setGreen(double green);
		void					setBlue(double blue);

	private:
		double					_r;
		double					_g;
		double					_b;

		void					_autoClamp(void);
};

#endif
