/**
 * @file   Entity.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of an entity.
 */
#include "Entity.h"
#include <stdexcept>

/**
 * Construct an entity.
 *
 * @param name
 */
Entity::Entity(const string& name)
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
void Entity::load(ifstream& file)
{
	string token;

	file >> token;
	if ( token != "name" ) {
		throw runtime_error("Invalid attribute \"" + token + "\"");
	}

	file >> token;
	this->name = token;
}

/**
 * Dump an entity to a file.
 *
 * @param file
 */
void Entity::dump(ofstream& file)
{
	file << "Name: " << this->name << '\n';
}