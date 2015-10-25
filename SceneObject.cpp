/**
 * @file   SceneObject.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of a scene object.
 */
#include "SceneObject.h"
#include <stdexcept>

/**
 * Construct a default scene object.
 */
SceneObject::SceneObject()
{
	Entity();

	this->color = (color_t) {255, 255, 255};
	this->diffuse = Vector();
	this->reflective = Vector();
}

/**
 * Load a scene object from a file.
 *
 * @param file
 */
void SceneObject::load(std::ifstream& file)
{
	std::string token;

	Entity::load(file);

	file >> token;
	while ( token != ";" ) {
		if ( token == "color" ) {
			unsigned char r, g, b;

			// TODO: overload >> for color_t to include other formats
			file >> r >> g >> b;
			this->color = (color_t) {r, g, b};
		}
		else if ( token == "diffuse" ) {
			file >> this->diffuse;
		}
		else if ( token == "reflective" ) {
			file >> this->reflective;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		file >> token;
	}
}

/**
 * Dump a scene object to a file.
 *
 * @param file
 */
void SceneObject::dump(std::ofstream& file) const
{
	Entity::dump(file);

	// TODO: overload << for color_t
	file << "Color: " << this->color.r << this->color.g << this->color.b << '\n'
	     << "Diffuse intensity: " << this->diffuse << '\n'
	     << "Reflectivity: " << this->reflective << '\n';
}