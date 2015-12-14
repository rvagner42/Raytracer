/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Scene.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 09:08:31 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/14 14:07:52 by rvagner             '*+###+*'           */
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

//----- Getters & Setters -----
		void					addObject(Object *obj);

	private:
		std::vector<Object *>		_objects;
};

#endif
