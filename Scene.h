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

#include "Entity.h"
#include "Window.h"
#include "Image.h"
#include "SceneObject.h"
#include "PointLight.h"
#include <list>

class Scene : public Entity {
private:
	/**
	 * For variables that could be any subclass of an abstract class, we must
	 * use a pointer of the abstract class.
	 */
	std::list<SceneObject*> objects;
	std::list<PointLight> lights;
	Window window;
	Image image;  // TODO: consider moving image to Window

public:
	Scene();

	void load(std::ifstream&);
	void dump(std::ofstream&) const;
};

#endif