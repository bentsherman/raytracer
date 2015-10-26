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
 * Load a point light from an input stream.
 *
 * @param is
 */
void PointLight::load(std::istream& is)
{
	std::string token;

	Entity::load(is);

	is >> token;
	while ( token != ";" ) {
		if ( token == "center" ) {
			is >> this->center;
		}
		else if ( token == "color" ) {
			is >> this->color;
		}
		else if ( token == "brightness" ) {
			is >> this->brightness;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		is >> token;
	}
}

/**
 * Dump a point light to an output stream.
 *
 * @param os
 */
void PointLight::dump(std::ostream& os) const
{
	Entity::dump(os);

	os << "Center: " << this->center << '\n'
	   << "Color: " << this->color << '\n'
	   << "Brightness: " << this->brightness << '\n';
}