/**
 * @file   PointLight.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a point light.
 */
#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Entity.h"
#include "Vector.h"
#include "Image.h"
// #include "Scene.h"
// #include "SceneObject.h"

class PointLight : public Entity {
private:
	Vector center;
	color_t color;
	double brightness;

public:
	PointLight();

	Vector get_center() const;
	color_t get_color() const;
	double get_brightess() const;
	// Vector process_light(const Scene&, const SceneObject&, hitinfo_t*) const;

	friend std::ostream& operator<<(std::ostream&, const PointLight&);
	friend std::istream& operator>>(std::istream&, PointLight&);
};

#endif