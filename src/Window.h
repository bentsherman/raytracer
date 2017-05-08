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
	Vector viewpoint;
	Vector ambient;

public:
	Window();

	double get_width() const;
	double get_height() const;
	int get_cols() const;
	Vector get_viewpoint() const;
	Vector get_ambient() const;

	friend std::ostream& operator<<(std::ostream&, const Window&);
	friend std::istream& operator>>(std::istream&, Window&);
};

#endif