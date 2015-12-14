/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   main.cpp                                           .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 13:03:00 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/14 08:53:47 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Process.hpp"
#include "raytracer.h"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Image.hpp"

void		draw_pixels(Image &image, Camera &cam, Sphere &sphere)
{
	int	x = 0;
	while (x < W)
	{
		int	y = 0;
		while (y < H)
		{
			double t = -1;
			if ((t = sphere.intersect(cam.build_ray(x + W * 0.5, y))) > 0)
				image.setPixel(x, y, sphere.getColor());
			else
				image.setPixel(x, y, 0x000000);
			y++;
		}
		x++;
	}
	image.draw();
}

int			main(void)
{
	Process			process;
	SDL_Surface		*screen = process.getScreen();
	SDL_Event		*ev = new SDL_Event();
	Uint8 const		*keys = SDL_GetKeyboardState(NULL);
	Image			image(W, H, screen);
	Camera			camera(
			Point(0.0, 0.0, 100.0),
			Point(0.0, 0.0, 0.0),
			Vector(Point(0.0, 1.0, 0.0)),
			100.0,
			100.0,
			W / H
			);
	Sphere			sphere(Point(0.0, 0.0, 0.0), 8.0, 0xFF0000);

	draw_pixels(image, camera, sphere);
	process.update();
	while (true)
	{
		SDL_PollEvent(ev);
		if (ev->type == SDL_QUIT)
			break ;
		else if (ev->type == SDL_KEYDOWN)
		{
			if (keys[SDL_SCANCODE_ESCAPE])
				break ;
		}
		if (process.check_ticks(500))
		{
			draw_pixels(image, camera, sphere);
			process.update();
		}
	}

	delete ev;
	return (0);
}
