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
 * Load a window from a file.
 *
 * @param file
 */
void Window::load(std::ifstream& file)
{
	std::string token;

	Entity::load(file);

	file >> token;
	while ( token != ";" ) {
		if ( token == "width" ) {
			file >> this->width;
		}
		else if ( token == "height" ) {
			file >> this->height;
		}
		else if ( token == "columns" ) {
			file >> this->cols;
		}
		else if ( token == "viewpoint" ) {
			file >> this->viewPoint;
		}
		else if ( token == "ambient" ) {
			file >> this->ambient;
		}
		else {
			throw std::runtime_error("invalid or duplicate key \"" + token + "\"");
		}

		file >> token;
	}
}

/**
 * Dump a window to a file.
 *
 * @param file
 */
void Window::dump(std::ofstream& file) const
{
	Entity::dump(file);

	file << "Window Width: " << this->width << '\n'
	     << "Window Height: " << this->height << '\n'
	     << "Pixel Width: " << this->cols << '\n'
	     << "Viewpoint: " << this->viewPoint << '\n'
	     << "Ambient intensity: " << this->ambient << '\n';
}