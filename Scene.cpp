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
 * Load a scane from a file.
 *
 * @param file
 */
void Scene::load(std::ifstream& file)
{
	std::string token;

	Entity::load(file);

	while ( file ) {
		file >> token;

		if ( token == "window" ) {
			this->window.load(file);

			this->image = Image(
				this->window.get_cols(),
				this->window.get_cols() * this->window.get_height()
					/ this->window.get_width(),
				255
			);
		}
		else if ( token == "plane" ) {
			// ...
		}
		else if ( token == "sphere" ) {
			// ...
		}
		else if ( token == "pointlight" ) {
			PointLight light;

			light.load(file);
			this->lights.push_back(light);
		}
		else {
			throw std::runtime_error("Unknown token \"" + token + "\"");
		}
	}
}

/**
 * Dump a scane to a file.
 *
 * @param file
 */
void Scene::dump(std::ofstream& file) const
{
	Entity::dump(file);

	// TODO: move pixel height to Window class ?
	this->window.dump(file);
	file << "Pixel Height: " << this->image.get_rows() << '\n';

	file << "Scene Objects:\n";
	for ( std::list<SceneObject*>::const_iterator iter = this->objects.begin();
			iter != this->objects.end(); iter++ ) {
		(*iter)->dump(file);
	}

	file << "Point Lights:\n";
	for ( std::list<PointLight>::const_iterator iter = this->lights.begin();
			iter != this->lights.end(); iter++ ) {
		iter->dump(file);
	}
}