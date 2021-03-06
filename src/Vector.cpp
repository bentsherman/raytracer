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
double Vector::get_x() const
{
	return this->x;
}

/**
 * Get the y coordinate of a vector.
 *
 * @return y coordinate of the vector
 */
double Vector::get_y() const
{
	return this->y;
}

/**
 * Get the z coordinate of a vector.
 *
 * @return z coordinate of the vector
 */
double Vector::get_z() const
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
 * Set the x coordinate of a vector.
 *
 * @param x  new x coordinate
 */
void Vector::set_x(double x)
{
	this->x = x;
}

/**
 * Set the y coordinate of a vector.
 *
 * @param y  new y coordinate
 */
void Vector::set_y(double y)
{
	this->y = y;
}

/**
 * Set the z coordinate of a vector.
 *
 * @param z  new z coordinate
 */
void Vector::set_z(double z)
{
	this->z = z;
}

/**
 * Check whether two vectors are equal.
 */
bool Vector::operator==(const Vector& rhs) const
{
	return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
}

bool Vector::operator!=(const Vector& rhs) const
{
	return !(*this == rhs);
}

/**
 * Get the sum of two vectors.
 */
Vector Vector::operator+(const Vector& rhs) const
{
	return Vector(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

/**
 * Get the difference of two vectors.
 */
Vector Vector::operator-(const Vector& rhs) const
{
	return Vector(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

/**
 * Get the product of this vector and a scalar.
 */
Vector Vector::operator*(const double& c) const
{
	return Vector(c * this->x, c * this->y, c * this->z);
}

/**
 * Get the quotient of this vector and a scalar.
 */
Vector Vector::operator/(const double& c) const
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
 * Get the reflection of this vector against a normal vector.
 *
 * @param N  unit vector
 * @return reflection of this vector against N
 */
Vector Vector::reflect(const Vector& N) const
{
	Vector U = this->unit() * -1;

	return N * 2 * U.dot(N) - U;
}

/**
 * Print a vector to an output stream.
 */
std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "(" << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << ")";
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