/**
 * @file   Sphere.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a sphere.
 */
#include "Sphere.h"
#include <math.h>
#include <stdexcept>

/**
 * Read a sphere from an input stream.
 *
 * @param is
 */
void Sphere::load(std::istream& is)
{
	std::string token;

	SceneObject::load(is);

	is >> token;
	while ( token != ";" ) {
		if ( token == "center" ) {
			is >> this->center;
		}
		else if ( token == "radius" ) {
			is >> this->radius;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		is >> token;
	}
}

/**
 * Write a sphere to an output stream.
 *
 * @param os
 */
void Sphere::dump(std::ostream& os) const
{
	os << "sphere" << '\n';

	SceneObject::dump(os);

	os << "  center: " << this->center << '\n'
	   << "  radius: " << this->radius << '\n';
}

/**
 * Get whether a ray hits the sphere.
 *
 * Using the following relation,
 *   t = (-b - sqrt(b^2 - 4*a*c))/(2*a)
 * where
 *   a = D dot D,
 *   b = 2 * (V' dot D),
 *   c = V' dot V' - r^2,
 *   V' = V - C,
 *
 * a hit occurs if
 *   b^2 - 4*a*c > 0 AND t > 0 AND H_z = (V + t*D)_z <= 0
 *
 * @param V    origin of the ray
 * @param D    direction of the ray
 * @param hit  hit paramters
 * @return true if a hit occures, false otherwise
 */
bool Sphere::hits(const Vector& V, const Vector& D, hitinfo_t* hit) const
{
	const Vector& C = this->center;
	const double& r = this->radius;

	Vector V_ = V - C;
	double a = D.dot(D);
	double b = 2 * V_.dot(D);
	double c = V_.dot(V_) - r*r;

	double radical = b*b - 4*a*c;

	if ( radical > 0 ) {
		double t = (-b - sqrt(radical)) / (2 * a);

		if ( t > 0 ) {
			Vector H = V + D * t;

			if ( H.get_z() <= 0 ) {
				hit->point = H;
				hit->normal = (H - C).unit();
				hit->distance = t;

				return true;
			}
		}
	}

	return false;
}