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
			file >> this->color;
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

	file << "Color: " << this->color << '\n'
	     << "Diffuse intensity: " << this->diffuse << '\n'
	     << "Reflectivity: " << this->reflective << '\n';
}