/**
 * @file   Sphere.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a sphere.
 */
#ifndef SPHERE_H
#define SPHERE_H

#include "SceneObject.h"

class Sphere : public SceneObject {
private:
	Vector center;
	double radius;

public:
	Sphere();

	void load(std::istream&);
	void dump(std::ostream&) const;

	bool hits(const Vector&, const Vector&, hitinfo_t*) const;
};

#endif