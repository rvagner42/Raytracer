/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Color.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/15 18:03:49 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 18:16:08 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Color.hpp"

Color::Color(void)
{
	this->_r_amb = 25.0;
	this->_g_amb = 25.0;
	this->_b_amb = 25.0;

	this->_k_diff = 0.1;
	this->_r_diff = 0.0;
	this->_g_diff = 0.0;
	this->_b_diff = 0.0;

	this->_k_spec = 0.5;
	this->_r_spec = 0.0;
	this->_g_spec = 0.0;
	this->_b_spec = 0.0;
}

Color::Color(double r, double g, double b)
{
	this->_r_amb = r * 0.2;
	this->_g_amb = g * 0.2;
	this->_b_amb = b * 0.2;

	this->_k_diff = 0.1;
	this->_r_diff = 0.0;
	this->_g_diff = 0.0;
	this->_b_diff = 0.0;

	this->_k_spec = 0.5;
	this->_r_spec = 0.0;
	this->_g_spec = 0.0;
	this->_b_spec = 0.0;
}
