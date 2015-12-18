/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Object.hpp                                         .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 15:04:21 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 08:29:34 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "raytracer.h"
# include "Ray.hpp"
# include "Color.hpp"

class Object
{
	public:
//----- Member functions -----
		virtual double		intersect(Ray const &ray) = 0;
		virtual Vector		getNormal(Vector const &p_intersect, Vector &v_normal) = 0;

//----- Getters & Setters
		Color		getColor(void) const;
		double		getKD(void) const;
		double		getKS(void) const;
		double		getPR(void) const;
		double		getN(void) const;
		double		getIOR(void) const;

		void		setColor(Color color);
		void		setKD(double kd);
		void		setKS(double ks);
		void		setPR(double pr);
		void		setN(double n);
		void		setIOR(double ior);

	protected:
		Color		_color;
		double		_kd;
		double		_ks;
		double		_pr;
		double		_n;
		double		_ior;
};

#endif
