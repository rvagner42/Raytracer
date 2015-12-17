/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   main.cpp                                           .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 13:03:00 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/16 15:04:28 by rvagner             '*+###+*'           */
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
			Vector(0.0, 0.0, 50.0),
			Vector(0.0, 0.0, 0.0),
			Vector(0.0, 1.0, 0.0),
			10.0,
			100.0,
			W / H
			);
	Sphere			sphere1(Vector(0.0, 0.0, 0.0), 8.0, Color(255.0, 0.0, 0.0));
	Sphere			sphere2(Vector(6.0, 5.0, 0.0), 5.0, Color(0.0, 255.0, 0.0));
	Sphere			sphere3(Vector(0.0, 5.0, 5.0), 5.0, Color(0.0, 0.0, 255.0));
	Sphere			sphere4(Vector(-3.0, -2.0, 15.0), 2.0, Color(0.0, 255.0, 255.0));
	Scene			scene;

	scene.addObject(&sphere1);
	scene.addObject(&sphere2);
	scene.addObject(&sphere3);
	scene.addObject(&sphere4);

	scene.addLight(Vector(5.0, 9.0, 10.0));

	scene.computeImage(image, camera);
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
			else
			{
				int x = 0, y = 0;
				if (keys[SDL_SCANCODE_LEFT])
					x -= 1;
				if (keys[SDL_SCANCODE_RIGHT])
					x += 1;
				if (keys[SDL_SCANCODE_UP])
					y += 1;
				if (keys[SDL_SCANCODE_DOWN])
					y -= 1;
				camera.move(x, y);
				scene.computeImage(image, camera);
				process.update();
			}
		}
	}

	delete ev;
	return (0);
}
