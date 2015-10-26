/**
 * @file   Window.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of a window.
 */
#include "Window.h"
#include <stdexcept>

/**
 * Construct a default window.
 */
Window::Window()
{
	Entity();

	this->width = 4;
	this->height = 4;
	this->cols = 600;
	this->viewPoint = Vector(0, 0, 5);
	this->ambient = Vector(1, 1, 1);
}

/**
 * Get the width of a window.
 */
double Window::get_width() const
{
	return this->width;
}

/**
 * Get the height of a window.
 */
double Window::get_height() const
{
	return this->height;
}

/**
 * Get the pixel width of a window.
 */
int Window::get_cols() const
{
	return this->cols;
}

/**
 * Load a window from an input stream.
 *
 * @param is
 */
void Window::load(std::istream& is)
{
	std::string token;

	Entity::load(is);

	is >> token;
	while ( token != ";" ) {
		if ( token == "width" ) {
			is >> this->width;
		}
		else if ( token == "height" ) {
			is >> this->height;
		}
		else if ( token == "columns" ) {
			is >> this->cols;
		}
		else if ( token == "viewpoint" ) {
			is >> this->viewPoint;
		}
		else if ( token == "ambient" ) {
			is >> this->ambient;
		}
		else {
			throw std::runtime_error("Invalid key \"" + token + "\"");
		}

		is >> token;
	}
}

/**
 * Dump a window to an output stream.
 *
 * @param os
 */
void Window::dump(std::ostream& os) const
{
	Entity::dump(os);

	os << "Window Width: " << this->width << '\n'
	     << "Window Height: " << this->height << '\n'
	     << "Pixel Width: " << this->cols << '\n'
	     << "Viewpoint: " << this->viewPoint << '\n'
	     << "Ambient intensity: " << this->ambient << '\n';
}