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
	Image image;  // TODO: consider moving image to Window
	std::list<SceneObject*> objects;
	std::list<PointLight> lights;

public:
	Scene();

	void load(std::istream&);
	void dump(std::ostream&) const;
};

#endif