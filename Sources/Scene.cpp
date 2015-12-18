/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Scene.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 11:04:55 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 16:32:09 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Scene.hpp"

Scene::Scene(void): _ka(0.2), _amb_color(Color(1.0, 1.0, 1.0))
{
	return ;
}

Scene::Scene(double ka): _ka(ka), _amb_color(Color(1.0, 1.0, 1.0))
{
	return ;
}

Scene::Scene(double ka, Color amb_color): _ka(ka), _amb_color(amb_color)
{
	return ;
}

Scene::~Scene(void)
{
	return ;
}

//----- Member functions -----

void								Scene::computeImage(Image &image, Camera &camera)
{
	for (int x = 0; x < W; x++)
	{
		for (int y = 0; y < H; y++)
		{
			double	t_min = INFINITY;
			Object	*closest = NULL;
			Ray		ray = camera.castRay(x, y);
			Color	final_color(0.0, 0.0, 0.0);

			std::vector<Object *>::iterator		it = this->_objects.begin();
			std::vector<Object *>::iterator		ite = this->_objects.end();
			while (it != ite)
			{
				double	t = -1;
				if ((t = (*it)->intersect(ray)) > 0 && t < t_min)
				{
					t_min = t;
					closest = (*it);
				}
				it++;
			}
			if (closest != NULL)
			{
				final_color = closest->getColor() * this->getKA() * closest->getKD();

				Vector		p_intersect = ray.getOrigin() + ray.getDirection() * (t_min - 0.000001);

				Vector		v_normal;
				closest->getNormal(p_intersect, v_normal);

				std::vector<Light *>::iterator		it2 = this->_lights.begin();
				std::vector<Light *>::iterator		ite2 = this->_lights.end();
				while (it2 != ite2)
				{
					Vector	v_light((*it2)->getPos() - p_intersect);
					v_light.normalize();
					Ray		to_light(p_intersect, v_light);

					if (this->checkShadows(to_light) == false) // check if obstruction
					{
						// diffuse
						double	theta = v_normal.dotProduct(v_light);
						theta = (theta < 0.0) ? 0.0 : theta;
						final_color = final_color + (closest->getColor() * closest->getKD()
								* (*it2)->getColor() * theta);

						// specular
						Vector	v_view = camera.getEye() - p_intersect;
						v_view.normalize();
						double	phi = v_view.dotProduct(v_normal);
						phi = (phi < 0.0) ? 0.0 : phi;
						Vector	v_reflexion = v_view + v_normal * (2 * phi) - v_light;
						v_reflexion.normalize();
						final_color = final_color + (*it2)->getColor() * closest->getKS()
							* pow(v_reflexion.dotProduct(v_view), closest->getN());
					}
					it2++;
				}
			}
			image.setPixel(x, y, final_color.computeColor());
		}
	}
	image.draw();
}

bool							Scene::checkShadows(Ray const &ray)
{
	std::vector<Object *>::iterator		it = this->_objects.begin();
	std::vector<Object *>::iterator		ite = this->_objects.end();
	while (it != ite)
	{
		if ((*it)->intersect(ray) > 0)
			return (true);
		it++;
	}
	return (false);
}

//----- Getters & Setters -----

double							Scene::getKA(void) const
{
	return (this->_ka);
}

Color							Scene::getAmbColor(void) const
{
	return (this->_amb_color);
}

void							Scene::setKA(double ka)
{
	this->_ka = ka;
}

void							Scene::setAmbColor(Color amb_color)
{
	this->_amb_color = amb_color;
}

void							Scene::addObject(Object *obj)
{
	this->_objects.push_back(obj);
}

void							Scene::addLight(Light *light)
{
	this->_lights.push_back(light);
}
