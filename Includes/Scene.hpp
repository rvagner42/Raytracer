/* ************************************************************************** */
/*                                                                            */
/*                                                           .:.              */
/*   Scene.hpp                                          .+:  :+:  :+.         */
/*                                                     +:+   +:+   :+:        */
/*   By: rvagner <rvagner@student.42.fr>              :#+    +#+    +#:       */
/*                                                     +#+   '+'   +#+        */
/*   Created:  2015/12/14 09:08:31 by rvagner           +#+,     ,+#+         */
/*   Modified: 2015/12/18 11:14:44 by rvagner             '*+###+*'           */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "raytracer.h"
# include "Image.hpp"
# include "Object.hpp"
# include "Camera.hpp"
# include "Light.hpp"

class Scene
{
	public:
		Scene(void);
		Scene(double ka);
		Scene(double ka, Color amb_color);
		virtual ~Scene(void);

//----- Member functions -----
		void					computeImage(Image &image, Camera &camera);
		bool					checkShadows(Ray const &ray);

//----- Getters & Setters -----
		double					getKA(void) const;
		Color					getAmbColor(void) const;

		void					setKA(double ka);
		void					setAmbColor(Color amb_color);

		void					addObject(Object *obj);
		void					addLight(Light *light);

	private:
		double						_ka;
		Color						_amb_color;
		std::vector<Object *>		_objects;
		std::vector<Light *>		_lights;
};

#endif
