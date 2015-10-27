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
 * Write a window to an output stream.
 *
 * @param os
 */
std::ostream& operator<<(std::ostream& os, const Window& window)
{
	os << "window" << '\n'
	   << (Entity) window
	   << "  width: " << window.width << '\n'
	   << "  height: " << window.height << '\n'
	   << "  columns: " << window.cols << '\n'
	   << "  rows: " << (int)(window.cols * window.height / window.width) << '\n'
	   << "  viewpoint: " << window.viewPoint << '\n'
	   << "  ambient: " << window.ambient << '\n';

	return os;
}

/**
 * Read a window from an input stream.
 *
 * @param is
 */
std::istream& operator>>(std::istream& is, Window& window)
{
	std::string token;

	is >> (Entity&) window;

	is >> token;
	while ( token != ";" ) {
		if ( token == "width" ) {
			is >> window.width;
		}
		else if ( token == "height" ) {
			is >> window.height;
		}
		else if ( token == "columns" ) {
			is >> window.cols;
		}
		else if ( token == "viewpoint" ) {
			is >> window.viewPoint;
		}
		else if ( token == "ambient" ) {
			is >> window.ambient;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		is >> token;
	}

	return is;
}