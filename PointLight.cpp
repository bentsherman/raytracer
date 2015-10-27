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
 * Write a point light to an output stream.
 *
 * @param os
 */
std::ostream& operator<<(std::ostream& os, const PointLight& light)
{
	os << "pointlight" << '\n'
	   << (Entity) light
	   << "  center: " << light.center << '\n'
	   << "  color: " << light.color << '\n'
	   << "  brightness: " << light.brightness << '\n';

	return os;
}

/**
 * Read a point light from an input stream.
 *
 * @param is
 */
std::istream& operator>>(std::istream& is, PointLight& light)
{
	std::string token;

	is >> (Entity&) light;

	is >> token;
	while ( token != ";" ) {
		if ( token == "center" ) {
			is >> light.center;
		}
		else if ( token == "color" ) {
			is >> light.color;
		}
		else if ( token == "brightness" ) {
			is >> light.brightness;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		is >> token;
	}

	return is;
}