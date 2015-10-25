/**
 * @file   PointLight.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of a point light.
 */
#include "PointLight.h"
#include <stdexcept>

/**
 * Construct a default point light.
 */
PointLight::PointLight()
{
	Entity();

	center = Vector();
	color = (color_t) {0, 0, 0};
	brightness = 0.0;
}

/**
 * Get the center of a point light.
 */
Vector PointLight::get_center() const
{
	return this->center;
}

/**
 * Get the color of a point light.
 */
color_t PointLight::get_color() const
{
	return this->color;
}

/**
 * Get the brightness of a point light.
 */
double PointLight::get_brightess() const
{
	return this->brightness;
}

/**
 * Load a point light from a file.
 *
 * @param file
 */
void PointLight::load(std::ifstream& file)
{
	std::string token;

	Entity::load(file);

	file >> token;
	while ( token != ";" ) {
		if ( token == "center" ) {
			file >> this->center;
		}
		else if ( token == "color" ) {
			file >> this->color;
		}
		else if ( token == "brightness" ) {
			file >> this->brightness;
		}
		else {
			throw std::runtime_error("Invalid key \"" + token + "\"");
		}

		file >> token;
	}
}

/**
 * Dump a point light to a file.
 *
 * @param file
 */
void PointLight::dump(std::ofstream& file) const
{
	Entity::dump(file);

	file << "Center: " << this->center << '\n'
	     << "Color: " << this->color << '\n'
	     << "Brightness: " << this->brightness << '\n';
}