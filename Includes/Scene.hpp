/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Scene.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 09:08:31 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/15 17:05:03 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "raytracer.h"
# include "Image.hpp"
# include "Object.hpp"
# include "Camera.hpp"

class Scene
{
	public:
		Scene(void);
		~Scene(void);

//----- Member functions -----
		void					computeImage(Image &image, Camera &camera);
		Uint32					computeColor(Vector p, double t, Ray &ray, Uint32 color);

//----- Getters & Setters -----
		void					addObject(Object *obj);
		void					addLight(Vector light);

	private:
		std::vector<Object *>		_objects;
		std::vector<Vector>			_lights;
};

#endif
