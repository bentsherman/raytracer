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

#include <fstream>
#include <string>

using namespace std;

class Entity {
private:
	string name;

public:
	Entity(const string&);
	Entity();

	void load(ifstream&);
	void dump(ofstream&);
};

#endif