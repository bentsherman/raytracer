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
 * Destruct a scene object.
 */
SceneObject::~SceneObject()
{

}

/**
 * Load a scene object from an input stream.
 *
 * @param is
 */
void SceneObject::load(std::istream& is)
{
	std::string token;

	Entity::load(is);

	is >> token;
	while ( token != ";" ) {
		if ( token == "color" ) {
			is >> this->color;
		}
		else if ( token == "diffuse" ) {
			is >> this->diffuse;
		}
		else if ( token == "reflective" ) {
			is >> this->reflective;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		is >> token;
	}
}

/**
 * Dump a scene object to an output stream.
 *
 * @param os
 */
void SceneObject::dump(std::ostream& os) const
{
	Entity::dump(os);

	os << "Color: " << this->color << '\n'
	   << "Diffuse intensity: " << this->diffuse << '\n'
	   << "Reflectivity: " << this->reflective << '\n';
}