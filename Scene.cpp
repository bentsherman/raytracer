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
 * Write a scane to an output stream.
 *
 * @param os
 */
std::ostream& operator<<(std::ostream& os, const Scene& scene)
{
	os << scene.window << '\n';

	for ( std::list<SceneObject*>::const_iterator iter = scene.objects.begin();
			iter != scene.objects.end(); iter++ ) {
		os << **iter << '\n';
	}

	for ( std::list<PointLight>::const_iterator iter = scene.lights.begin();
			iter != scene.lights.end(); iter++ ) {
		os << *iter << '\n';
	}

	return os;
}

/**
 * Read a scane from an input stream.
 *
 * @param is
 */
std::istream& operator>>(std::istream& is, Scene& scene)
{
	std::string token;

	while ( is >> token ) {
		if ( token == "window" ) {
			is >> scene.window;

			Image image(
				scene.window.get_cols(),
				scene.window.get_cols() * scene.window.get_height()
					/ scene.window.get_width(),
				255
			);
			scene.image = image;
		}
		else if ( token == "plane" ) {
			Plane* plane = new Plane;

			is >> *plane;
			scene.objects.push_back(plane);
		}
		else if ( token == "sphere" ) {
			Sphere* sphere = new Sphere;

			is >> *sphere;
			scene.objects.push_back(sphere);
		}
		else if ( token == "pointlight" ) {
			PointLight light;

			is >> light;
			scene.lights.push_back(light);
		}
		else {
			throw std::runtime_error("unknown token \"" + token + "\"");
		}
	}

	return is;
}