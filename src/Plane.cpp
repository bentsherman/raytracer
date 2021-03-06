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
 * Read a plane from an input stream.
 *
 * @param is
 */
void Plane::load(std::istream& is)
{
	std::string token;
	Vector orient1, orient2;

	SceneObject::load(is);

	is >> token;
	while ( token != ";" ) {
		if ( token == "point" ) {
			is >> this->point;
		}
		else if ( token == "orient1" ) {
			is >> orient1;
		}
		else if ( token == "orient2" ) {
			is >> orient2;
		}
		else {
			throw std::runtime_error("invalid key \"" + token + "\"");
		}

		is >> token;
	}

	this->normal = orient1.cross(orient2).unit();
}

/**
 * Write a plane to an output stream.
 *
 * @param os
 */
void Plane::dump(std::ostream& os) const
{
	os << "plane" << '\n';

	SceneObject::dump(os);

	os << "  point: " << this->point << '\n'
	   << "  normal: " << this->normal << '\n';
}

/**
 * Get whether a ray hits the plane.
 *
 * Using the following relation,
 *   t = (N dot (P - V))/(N dot D),
 * 
 * a hit occurs if
 *   N dot D != 0 AND t > 0 AND H_z = (V + t*D)_z <= 0
 *
 * @param V    origin of the ray
 * @param D    direction of the ray
 * @param hit  hit paramters
 * @return true if a hit occures, false otherwise
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

			if ( H.get_z() <= 0 ) {
				hit->point = H;
				hit->normal = N;
				hit->distance = t;

				if ( D.dot(hit->normal) > 0 ) {
					hit->normal = hit->normal * -1;
				}

				return true;
			}
		}
	}

	return false;
}