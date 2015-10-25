/**
 * @file   Window.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a window. A window is the view point into a scene.
 */
#ifndef WINDOW_H
#define WINDOW_H

#include "Entity.h"
#include "Vector.h"

class Window : public Entity {
private:
	double width;
	double height;
	int cols;
	Vector viewPoint;
	Vector ambient;

public:
	Window();

	double get_width() const;
	double get_height() const;
	int get_cols() const;

	void load(std::ifstream&);
	void dump(std::ofstream&) const;
};

#endif