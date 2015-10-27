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
 * Destruct an entity.
 */
Entity::~Entity()
{

}

/**
 * Write an entity to an output stream.
 *
 * @param os
 */
std::ostream& operator<<(std::ostream& os, const Entity& entity)
{
	os << "  name: " << entity.name << '\n';

	return os;
}

/**
 * Read an entity from an input stream.
 *
 * @param is
 */
std::istream& operator>>(std::istream& is, Entity& entity)
{
	std::string token;

	is >> token;
	while ( token != ";" ) {
		if ( token == "name" ) {
			is >> entity.name;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		is >> token;
	}

	return is;
}