/**
 * @file   Image.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of an image.
 */
#include "Image.h"
#include <fstream>
#include <stdexcept>
#include <string>

/**
 * Print a color to an output stream.
 */
std::ostream& operator<<(std::ostream& os, const color_t& c)
{
	os << c.r << ' ' << c.g << ' ' << c.b;
	return os;
}

/**
 * Read a color from an input stream.
 */
std::istream& operator>>(std::istream& is, color_t& c)
{
	// TODO: include color name and hexadecimal formats
	is >> c.r >> c.g >> c.b;
	return is;
}

/**
 * Construct an image from a PPM file.
 *
 * @param fname name of PPM file to read
 */
Image::Image(const char* fname)
{
	std::ifstream file(fname, std::ios_base::binary);
	std::string header;
	int cols, rows, brightness;

	/* check for the PPM header */
	file >> header;
	if ( header != "P6" ) {
		throw std::runtime_error("PPM file does not start with \"P6\"");
	}

	/* read image parameters */
	// TODO: check for comments, missing values
	file >> cols
	     >> rows
	     >> brightness;

	/* initialize members */
	this->cols = cols;
	this->rows = rows;
	this->brightness = brightness;
	this->pixels = new color_t[rows * cols];

	/* read pixels */
	file.read((char*) this->pixels, rows * cols * sizeof(color_t));
	if ( !file ) {
		throw std::runtime_error("PPM file truncated");
	}

	file.close();
}

/**
 * Destruct an image.
 */
Image::~Image()
{
	delete[] this->pixels;
}

/**
 * Write an image to a PPM file.
 *
 * @param fname  name of PPM file to write
 */
void Image::write(const char* fname) const
{
	std::ofstream file(fname, std::ios_base::binary);

	file << "P6 "
	     << this->cols << ' '
	     << this->rows << ' '
	     << this->brightness << '\n';
	file.write((char*) this->pixels, this->rows * this->cols * sizeof(color_t));

	file.close();
}