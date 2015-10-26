/**
 * @file   Plane.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a plane.
 */
#ifndef PLANE_H
#define PLANE_H

#include "SceneObject.h"

class Plane : public SceneObject {
private:
	// Vector orient1;
	// Vector orient2;
	Vector point;
	Vector normal;

public:
	Plane();

	void load(std::ifstream&);
	void dump(std::ofstream&) const;

	bool hits(const Vector&, const Vector&, hitinfo_t*) const;
};

#endif