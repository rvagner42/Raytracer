/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   main.cpp                                           .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/12 13:03:00 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 16:28:11 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#include "Process.hpp"
#include "raytracer.h"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "Light.hpp"

int			main(void)
{
	Process			process;
	SDL_Event		*ev = new SDL_Event();
	Uint8 const		*keys = SDL_GetKeyboardState(NULL);
	Image			image(W, H, process.getScreen());
	Camera			camera(
			Vector(0.0, 0.0, 50.0),
			Vector(0.0, 0.0, 0.0),
			Vector(0.0, 1.0, 0.0),
			10.0, 100.0, W / H
			);
	Sphere			sphere1(Vector(0.0, 0.0, 0.0), 8.0, Color(1.0, 0.0, 0.0), 0.7, 0.8, 0.2, 100, 0.2);
	/*
	 *Sphere			sphere2(Vector(6.0, 5.0, 0.0), 5.0, Color(0.0, 1.0, 0.0), 0.7, 0.8, 0.2, 100, 0.2);
	 *Sphere			sphere3(Vector(0.0, 5.0, 5.0), 5.0, Color(0.0, 0.0, 1.0), 0.7, 0.8, 0.2, 100, 0.2);
	 *Sphere			sphere4(Vector(-3.0, -2.0, 15.0), 2.0, Color(0.0, 1.0, 1.0), 0.7, 0.8, 0.2, 100, 0.2);
	 */
	Scene			scene(0.3);

	scene.addObject(&sphere1);
	/*
	 *scene.addObject(&sphere2);
	 *scene.addObject(&sphere3);
	 *scene.addObject(&sphere4);
	 */

	Light			light1(Vector(5.0, 9.0, 10.0));

	scene.addLight(&light1);

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
		}
	}

	delete ev;
	return (0);
}
