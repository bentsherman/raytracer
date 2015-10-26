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

// TODO: consider replacing load/dump with >> and << for all objects
class Entity {
private:
	std::string name;

public:
	Entity(const std::string&);
	Entity();
	virtual ~Entity();

	void load(std::istream&);
	void dump(std::ostream&) const;
};

#endif