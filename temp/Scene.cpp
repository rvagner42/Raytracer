/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Scene.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 11:04:55 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 10:56:42 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Scene.hpp"

Scene::Scene(void)
{
	return ;
}

Scene::~Scene(void)
{
	return ;
}

//----- Member functions -----
void							Scene::computeImage(Image &image, Camera &camera)
{
	int			x;
	int			y;
	double		t_min;
	double		t;
	Object		*closest;
	Ray			ray;
	std::vector<Object *>::iterator	it;
	std::vector<Object *>::iterator	ite = this->_objects.end();

	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			t_min = INFINITY;
			closest = NULL;
			it = this->_objects.begin();
			ray = camera.build_ray(x, y);
			while (it != ite)
			{
				if ((t = (*it)->intersect(ray)) > 0)
				{
					if (t < t_min)
					{
						t_min = t;
						closest = *it;
					}
				}
				it++;
			}
			if (closest != NULL)
				image.setPixel(x, y, computeColor(closest->getCenter(), t_min, ray, closest->getColor()));
			else
				image.setPixel(x, y, 0x000000);
			y++;
		}
		x++;
	}
	image.draw();
}

Uint32							Scene::computeColor(Vector p, double t, Ray &ray, Color color)
{
	Vector			surface(ray.getOrigin() + ray.getDirection() * t);

	Vector			norm(surface, p);
	norm.normalize();
	Vector			light(this->_lights[0], surface);
	light.normalize();

	double			theta = norm.dotProduct(light);

	return (color.computeFinalColor(theta));
}

//----- Getters & Setters -----
void							Scene::addObject(Object *obj)
{
	this->_objects.push_back(obj);
}

void							Scene::addLight(Vector light)
{
	this->_lights.push_back(light);
}
