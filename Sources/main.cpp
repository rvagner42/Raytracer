/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   main.cpp                                           .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 13:03:00 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/14 15:14:33 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Process.hpp"
#include "raytracer.h"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Image.hpp"
#include "Scene.hpp"

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
	Sphere			sphere1(Point(0.0, 0.0, 0.0), 8.0, 0xFF0000);
	Sphere			sphere2(Point(6.0, 5.0, 0.0), 5.0, 0x00FF00);
	Sphere			sphere3(Point(0.0, 5.0, 5.0), 5.0, 0x0000FF);
	Sphere			sphere4(Point(-3.0, -2.0, 15.0), 2.0, 0x00FFFF);
	Scene			scene;

	scene.addObject(&sphere1);
	scene.addObject(&sphere2);
	scene.addObject(&sphere3);
	scene.addObject(&sphere4);

	scene.computeImage(image, camera);
	process.update();
	while (true)
	{
		if (process.check_ticks(100))
		{
			SDL_PollEvent(ev);
			if (ev->type == SDL_QUIT)
				break ;
			else if (ev->type == SDL_KEYDOWN)
			{
				if (keys[SDL_SCANCODE_ESCAPE])
					break ;
				int x = 0, y = 0, z = 0;
				if (keys[SDL_SCANCODE_DOWN])
					y += 1.5;
				if (keys[SDL_SCANCODE_UP])
					y -= 1.5;
				if (keys[SDL_SCANCODE_LEFT])
					x -= 1.5;
				if (keys[SDL_SCANCODE_RIGHT])
					x += 1.5;
				camera.move(x, y, z);
				scene.computeImage(image, camera);
				process.update();
			}
		}
	}

	delete ev;
	return (0);
}
