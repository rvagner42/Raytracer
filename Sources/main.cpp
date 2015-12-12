/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   main.cpp                                           .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 13:03:00 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/12 18:16:17 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Process.hpp"
#include "raytracer.h"
#include "Camera.hpp"
#include "Sphere.hpp"

void		draw_pixels(Pixel ***pixels, SDL_Surface *screen, Camera &cam, Sphere &sphere)
{
	int	x = 0;
	while (x < W)
	{
		int	y = 0;
		while (y < H)
		{
			double t = -1;
			(*pixels)[x][y].setColor(0x000000); // same as setColor(255, 0, 255);
			if ((t = sphere.intersect(cam.build_ray(x + W * 0.5, y))) > 0)
				(*pixels)[x][y].setColor(sphere.getColor());
			(*pixels)[x][y].draw(screen);
			y++;
		}
		x++;
	}

}

int			main(void)
{
	Process			process;
	SDL_Surface		*screen = process.getScreen();
	SDL_Event		*ev = new SDL_Event();
	Uint8 const		*keys = SDL_GetKeyboardState(NULL);
	Pixel			**pixels = new Pixel *[W];
	Camera			camera(
			Point(0.0, 0.0, 100.0),
			Point(0.0, 0.0, 0.0),
			Vector(Point(0.0, 1.0, 0.0)),
			100.0,
			100.0,
			W / H
			);
	Sphere			sphere(Point(0.0, 0.0, 0.0), 8.0, 0xFF0000);

	for (int i = 0; i < W; i++)
		pixels[i] = new Pixel[H];
	int	x = 0;
	while (x < W)
	{
		int	y = 0;
		while (y < H)
		{
			pixels[x][y].setX(x);
			pixels[x][y].setY(y);
			y++;
		}
		x++;
	}

	while (true)
	{
		if (process.check_ticks(60))
		{
			SDL_PollEvent(ev);
			if (ev->type == SDL_QUIT)
				break ;
			else if (ev->type == SDL_KEYDOWN)
			{
				if (keys[SDL_SCANCODE_ESCAPE])
					break ;
			}
			draw_pixels(&pixels, screen, camera, sphere);
			process.update();
		}
	}

	for (int i = 0; i < W; i++)
		delete [] pixels[i];
	delete [] pixels;
	delete ev;
	return (0);
}
