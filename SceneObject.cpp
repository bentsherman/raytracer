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
 * Get the color of the scene object.
 */
color_t SceneObject::get_color() const
{
	return this->color;
}

/**
 * Write a scene object to an output stream.
 *
 * @param os
 */
void SceneObject::dump(std::ostream& os) const
{
	os << (Entity&) *this
	   << "  color: " << this->color << '\n'
	   << "  diffuse: " << this->diffuse << '\n'
	   << "  reflective: " << this->reflective << '\n';
}

/**
 * Read a scene object from an input stream.
 *
 * @param is
 */
void SceneObject::load(std::istream& is)
{
	std::string token;

	is >> (Entity&) *this;

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

std::ostream& operator<<(std::ostream& os, const SceneObject& object)
{
	object.dump(os);

	return os;
}

std::istream& operator>>(std::istream& is, SceneObject& object)
{
	object.load(is);

	return is;
}