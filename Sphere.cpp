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
 * Construct a default sphere.
 */
Sphere::Sphere()
{
	// ...
}

/**
 * Load a sphere from a file.
 *
 * @param file
 */
void Sphere::load(std::ifstream& file)
{
	std::string token;

	SceneObject::load(file);

	file >> token;
	while ( token != ";" ) {
		if ( token == "center" ) {
			file >> this->center;
		}
		else if ( token == "radius" ) {
			file >> this->radius;
		}
		else {
			throw std::runtime_error("Invalid key \"" + token + "\"");
		}

		file >> token;
	}
}

/**
 * Dump a sphere to a file.
 *
 * @param file
 */
void Sphere::dump(std::ofstream& file) const
{
	SceneObject::dump(file);

	file << "Center: " << this->center << '\n'
	     << "Radius: " << this->radius << '\n';
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

			if ( H.getZ() <= 0 ) {
				hit->point = H;
				hit->normal = (H - C).unit();
				hit->distance = t;

				return true;
			}
		}
	}

	return false;
}