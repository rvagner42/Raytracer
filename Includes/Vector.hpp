/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Vector.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/11 21:47:29 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/11 22:01:44 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "Point.hpp"
# include <cmath>

class Vector
{
	public:
		Vector(void);
		Vector(Point const &dest);
		Vector(Point const &orig, Point const &dest);
		Vector(Vector const &src);
		virtual ~Vector(void);

//----- Operators -----

		Vector					&operator=(Vector const &src);

		Vector					operator+(Vector const &rhs);
		Vector					operator-(Vector const &rhs);
		Vector					operator*(Vector const &rhs);
		Vector					operator*(double const &rhs);

//----- Getters & Setters -----

		double					getX(void) const;
		double					getY(void) const;
		double					getZ(void) const;
		void					setX(double x);
		void					setY(double y);
		void					setZ(double z);

//----- Others -----

		void					normalize(void);
		double					magnitude(void) const;
		double					dotProduct(Vector const &rhs) const;

	private:
		double					_x;
		double					_y;
		double					_z;
};

std::ostream						&operator<<(std::ostream &o, Vector const &vector);

#endif
