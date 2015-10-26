/**
 * @file   Scene.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of a scene.
 */
#include "Scene.h"
#include <stdexcept>

/**
 * Construct a default scene.
 */
Scene::Scene()
{
	Entity();

	// ...
	this->image = Image(0, 0, 0);
}

/**
 * Load a scane from an input stream.
 *
 * @param is
 */
void Scene::load(std::istream& is)
{
	std::string token;

	Entity::load(is);

	while ( is ) {
		is >> token;

		if ( token == "window" ) {
			this->window.load(is);

			this->image = Image(
				this->window.get_cols(),
				this->window.get_cols() * this->window.get_height()
					/ this->window.get_width(),
				255
			);
		}
		else if ( token == "plane" ) {
			Plane plane;

			plane.load(is);
			this->objects.push_back(plane);
		}
		else if ( token == "sphere" ) {
			Sphere sphere;

			sphere.load(is);
			this->objects.push_back(sphere);
		}
		else if ( token == "pointlight" ) {
			PointLight light;

			light.load(is);
			this->lights.push_back(light);
		}
		else {
			throw std::runtime_error("Unknown token \"" + token + "\"");
		}
	}
}

/**
 * Dump a scane to an output stream.
 *
 * @param os
 */
void Scene::dump(std::ostream& os) const
{
	Entity::dump(os);

	// TODO: move pixel height to Window class ?
	this->window.dump(os);
	os << "Pixel Height: " << this->image.get_rows() << '\n';

	os << "Scene Objects:\n";
	for ( std::list<SceneObject*>::const_iterator iter = this->objects.begin();
			iter != this->objects.end(); iter++ ) {
		(*iter)->dump(os);
	}

	os << "Point Lights:\n";
	for ( std::list<PointLight>::const_iterator iter = this->lights.begin();
			iter != this->lights.end(); iter++ ) {
		iter->dump(os);
	}
}