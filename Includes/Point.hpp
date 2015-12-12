/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Point.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 21:36:28 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 10:19:36 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <iostream>

class Point
{
	public:
		Point(void);
		Point(double x, double y);
		Point(double x, double y, double z);
		Point(Point const &src);
		virtual ~Point(void);

//----- Operators -----

		Point			&operator=(Point const &src);

//----- Getters & Setters -----

		double			getX(void) const;
		double			getY(void) const;
		double			getZ(void) const;
		void			setX(double x);
		void			setY(double y);
		void			setZ(double z);

	private:
		double			_x;
		double			_y;
		double			_z;
};

std::ostream				&operator<<(std::ostream &o, Point const &point);

#endif
