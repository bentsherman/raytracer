/**
 * @file   Entity.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of an entity.
 */
#include "Entity.h"
#include <stdexcept>

/**
 * Construct an entity.
 *
 * @param name
 */
Entity::Entity(const std::string& name)
{
	this->name = name;
}

/**
 * Construct a default entity.
 */
Entity::Entity()
{

}

/**
 * Load an entity from an input stream.
 *
 * @param is
 */
void Entity::load(std::istream& is)
{
	std::string token;

	is >> token;
	if ( token != "name" ) {
		throw std::runtime_error("invalid key \"" + token + "\"");
	}

	is >> token;
	this->name = token;
}

/**
 * Dump an entity to an output stream.
 *
 * @param os
 */
void Entity::dump(std::ostream& os) const
{
	os << "Name: " << this->name << '\n';
}