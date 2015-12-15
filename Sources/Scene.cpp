/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Scene.cpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 11:04:55 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 15:55:04 by rvagner             '*+###+*'           */
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
			ray = camera.build_ray(x + W * 0.5, y);
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

Uint32							Scene::computeColor(Point p, double t, Ray &ray, Uint32 color)
{
	Point			surface(ray.getOrigin());
	Vector			dist(ray.getDirection() * t);

	surface.setX(surface.getX() + dist.getX());
	surface.setY(surface.getY() + dist.getY());
	surface.setZ(surface.getZ() + dist.getZ());

	Vector			norm(surface, p);
	norm.normalize();
	Vector			light(this->_lights[0], surface);
	light.normalize();

	double			theta = norm.dotProduct(light);
	theta = fmax(0.01, fmin(theta, 1.0));

	Uint8			r = ((color >> 16) & 0xFF);
	Uint8			g = ((color >> 8) & 0xFF);
	Uint8			b = ((color) & 0xFF); 
	r = r * theta;
	g = g * theta;
	b = b * theta;

	return (65536 * r + 256 * g + b);
}

//----- Getters & Setters -----
void							Scene::addObject(Object *obj)
{
	this->_objects.push_back(obj);
}

void							Scene::addLight(Point light)
{
	this->_lights.push_back(light);
}
