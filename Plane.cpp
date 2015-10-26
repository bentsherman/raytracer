/**
 * @file   Plane.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a plane.
 */
#include "Plane.h"
#include <stdexcept>

/**
 * Construct a default plane.
 */
Plane::Plane()
{
	// ...
}

/**
 * Load a plane from a file.
 *
 * @param file
 */
void Plane::load(std::ifstream& file)
{
	std::string token;
	Vector orient1, orient2;

	SceneObject::load(file);

	file >> token;
	while ( token != ";" ) {
		if ( token == "point" ) {
			file >> this->point;
		}
		else if ( token == "orient1" ) {
			file >> orient1;
		}
		else if ( token == "orient2" ) {
			file >> orient2;
		}
		else {
			throw std::runtime_error("Invalid key \"" + token + "\"");
		}

		file >> token;
	}

	this->normal = orient1.cross(orient2).unit();
}

/**
 * Dump a plane to a file.
 *
 * @param file
 */
void Plane::dump(std::ofstream& file) const
{
	SceneObject::dump(file);

	file << "Point: " << this->point << '\n'
	     << "Normal: " << this->normal << '\n';
}

/**
 * Get whether a ray hits the plane.
 *
 *  Using the following relation,
 *    t = (N dot (P - V))/(N dot D),
 * 
 *  a hit occurs if
 *    N dot D != 0 AND t > 0 AND H_z = (V + t*D)_z <= 0
 *
 * @param V    origin of the ray
 * @param D    direction of the ray
 * @param hit  hit paramters
 */
bool Plane::hits(const Vector& V, const Vector& D, hitinfo_t* hit) const
{
	const Vector& P = this->point;
	const Vector& N = this->normal;

	double denom = N.dot(D);

	if ( denom != 0 ) {
		double t = N.dot(P - V) / denom;

		if ( t >= 0 ) { // t > 0 ?
			Vector H = V + D * t;

			if ( H.getZ() <= 0 ) {
				hit->point = H;
				hit->normal = N;
				hit->distance = t;
				return true;
			}
		}
	}

	return false;
}