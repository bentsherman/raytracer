/**
 * @file   SceneObject.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a scene object. A scene object is the base class 
 * for every type of object in a scene.
 */
#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "Vector.h"
#include "Image.h"  // for color_t definition
#include "Entity.h"

typedef struct hitinfo_t {
	Vector point;
	Vector normal;
	double distance;
} hitinfo_t;

class SceneObject : public Entity {
private:
	color_t color;
	Vector diffuse;
	Vector reflective;

public:
	SceneObject();
	virtual ~SceneObject();

	color_t get_color() const;
	Vector get_diffuse() const;
	Vector get_reflective() const;

	virtual void load(std::istream&);
	virtual void dump(std::ostream&) const;

	virtual bool hits(const Vector&, const Vector&, hitinfo_t*) const = 0;

	friend std::ostream& operator<<(std::ostream&, const SceneObject&);
	friend std::istream& operator>>(std::istream&, SceneObject&);
};

#endif