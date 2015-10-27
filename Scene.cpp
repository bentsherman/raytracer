/**
 * @file   Scene.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of a scene.
 */
#include "Scene.h"
#include "Plane.h"
#include "Sphere.h"
#include <stdexcept>

/**
 * Construct a default scene.
 */
Scene::Scene()
{
	// ...
}

/**
 * Destruct a scene.
 */
Scene::~Scene()
{
	for ( std::list<SceneObject*>::iterator iter = this->objects.begin();
			iter != this->objects.end(); iter++ ) {
		delete *iter;
	}
}

/**
 * Load a scane from an input stream.
 *
 * @param is
 */
void Scene::load(std::istream& is)
{
	std::string token;

	while ( is >> token ) {
		if ( token == "window" ) {
			this->window.load(is);

			Image image(
				this->window.get_cols(),
				this->window.get_cols() * this->window.get_height()
					/ this->window.get_width(),
				255
			);
			this->image = image;
		}
		else if ( token == "plane" ) {
			Plane* plane = new Plane;

			plane->load(is);
			this->objects.push_back(plane);
		}
		else if ( token == "sphere" ) {
			Sphere* sphere = new Sphere;

			sphere->load(is);
			this->objects.push_back(sphere);
		}
		else if ( token == "pointlight" ) {
			PointLight light;

			light.load(is);
			this->lights.push_back(light);
		}
		else {
			throw std::runtime_error("unknown token \"" + token + "\"");
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
	this->window.dump(os);
	os << '\n';

	for ( std::list<SceneObject*>::const_iterator iter = this->objects.begin();
			iter != this->objects.end(); iter++ ) {
		(*iter)->dump(os);
		os << '\n';
	}

	for ( std::list<PointLight>::const_iterator iter = this->lights.begin();
			iter != this->lights.end(); iter++ ) {
		iter->dump(os);
		os << '\n';
	}
}