/**
 * @file   Vector.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of a vector.
 */
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

// TODO: review operator overloading, also for iostream
class Vector {
private:
	double x;
	double y;
	double z;

public:
	Vector(double x, double y, double z);
	Vector();
	Vector(const Vector& v);

	double getX() const;
	double getY() const;
	double getZ() const;
	double length() const;

	Vector operator+(const Vector& rhs) const;
	Vector operator-(const Vector& rhs) const;
	Vector operator*(const double& c) const;
	Vector operator/(const double& c) const;

	Vector unit() const;
	double dot(const Vector& rhs) const;
	Vector cross(const Vector& rhs) const;
};

std::ostream& operator<<(std::ostream&, const Vector&);
std::istream& operator>>(std::istream&, Vector&);

#endif