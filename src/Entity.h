/**
 * @file   Entity.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of an entity. An entity is the base class for every
 * object that is managed by the ray tracer.
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

class Entity {
private:
	std::string name;

public:
	virtual ~Entity();

	friend std::ostream& operator<<(std::ostream&, const Entity&);
	friend std::istream& operator>>(std::istream&, Entity&);
};

#endif