/**
 * @file   Scene.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a scene. A scene contains all objects and 
 * light sources, as well as a window into the space.
 */
#ifndef SCENE_H
#define SCENE_H

#include "Window.h"
#include "Image.h"
#include "SceneObject.h"
#include "PointLight.h"
#include <iostream>
#include <list>

class Scene {
private:
	Window window;
	Image* image;
	std::list<SceneObject*> objects;
	std::list<PointLight> lights;

	Vector gen_ray(int, int) const;
	Vector trace_ray(const Vector&, const Vector&, double);
	SceneObject* closest(const Vector&, const Vector&, hitinfo_t*);
	color_t render_pixel(int, int);

public:
	~Scene();

	void render();
	Image* get_image() const;

	friend std::ostream& operator<<(std::ostream&, const Scene&);
	friend std::istream& operator>>(std::istream&, Scene&);
};

#endif