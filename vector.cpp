/**
 * @file   Vector.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of a vector.
 */
#include "Vector.h"
#include <math.h>

/**
 * Construct a vector.
 *
 * @param x
 * @param y
 * @param z
 */
Vector::Vector(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

/**
 * Construct the zero vector.
 */
Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

/**
 * Construct a copy of a vector.
 *
 * @param v  vector to copy
 */
Vector::Vector(const Vector& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

/**
 * Get the x coordinate of a vector.
 *
 * @return x coordinate of the vector
 */
double Vector::getX() const
{
	return this->x;
}

/**
 * Get the y coordinate of a vector.
 *
 * @return y coordinate of the vector
 */
double Vector::getY() const
{
	return this->y;
}

/**
 * Get the z coordinate of a vector.
 *
 * @return z coordinate of the vector
 */
double Vector::getZ() const
{
	return this->z;
}

/**
 * Get the length of a vector.
 *
 * @return length of the vector
 */
double Vector::length() const
{
	return sqrt(this->dot(*this));
}

/**
 * Get the sum of two vectors.
 *
 * @param rhs  vector to add to this vector
 * @return     sum of this vector and rhs
 */
Vector Vector::operator+(const Vector& rhs) const
{
	return Vector(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

/**
 * Get the difference of two vectors.
 *
 * @param rhs  vector to subtract from this vector
 * @return     difference of this vector and rhs
 */
Vector Vector::operator-(const Vector& rhs) const
{
	return Vector(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

/**
 * Get the product of this vector and a scalar.
 *
 * @param c  scalar
 * @return   product of this vector and c
 */
Vector Vector::operator*(double c) const
{
	return Vector(c * this->x, c * this->y, c * this->z);
}

/**
 * Get the quotient of this vector and a scalar.
 *
 * @param c  scalar
 * @return   quotient of this vector and c
 */
Vector Vector::operator/(double c) const
{
	return (*this) * (1.0 / c);
}

/**
 * Get the unit vector with the same direction as this vector.
 *
 * @return unit vector with same direction as this vector
 */
Vector Vector::unit() const
{
	return (*this) / this->length();
}

/**
 * Get the dot product of two vectors.
 *
 * @param rhs  vector
 * @return     dot product of this vector and rhs
 */
double Vector::dot(const Vector& rhs) const
{
	return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
}

/**
 * Get the cross product of two vectors.
 *
 * @param rhs  vector
 * @return     cross product of this vector and rhs
 */
Vector Vector::cross(const Vector& rhs) const
{
	return Vector(
		this->y * rhs.z - this->z * rhs.y,
		this->z * rhs.x - this->x * rhs.z,
		this->x * rhs.y - this->y * rhs.x
	);
}

/**
 * Print a vector to an output stream.
 */
std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
	return os;
}

/**
 * Read a vector from an input stream.
 */
std::istream& operator>>(std::istream& is, Vector& v)
{
	double x, y, z;

	is >> x >> y >> z;
	v = Vector(x, y, z);

	return is;
}