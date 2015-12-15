/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Color.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/15 17:18:58 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 18:12:12 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

class Color
{
	public:
		Color(void);
		Color(double r, double g, double b);
		Color(double r, double g, double b, double k_diff, double k_spec);
		Color(Color const &src);
		~Color(void);

//----- Member functions -----
		void		setDiffuse(double theta);

		Uint32		getColor(void) const;

	private:
		double		_r_amb;
		double		_g_amb;
		double		_b_amb;

		double		_k_diff;
		double		_r_diff;
		double		_g_diff;
		double		_b_diff;

		double		_k_spec;
		double		_r_spec;
		double		_g_spec;
		double		_b_spec;
};

#endif
