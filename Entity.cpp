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
 * Load an entity from a file.
 *
 * @param file
 */
void Entity::load(std::ifstream& file)
{
	std::string token;

	file >> token;
	if ( token != "name" ) {
		throw std::runtime_error("Invalid key \"" + token + "\"");
	}

	file >> token;
	this->name = token;
}

/**
 * Dump an entity to a file.
 *
 * @param file
 */
void Entity::dump(std::ofstream& file) const
{
	file << "Name: " << this->name << '\n';
}