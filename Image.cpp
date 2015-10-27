/**
 * @file   Image.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of an image.
 */
#include "Image.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>

/**
 * Print a color to an output stream.
 */
std::ostream& operator<<(std::ostream& os, const color_t& c)
{
	os << (unsigned) c.r << ' ' << (unsigned) c.g << ' ' << (unsigned) c.b;
	return os;
}

/**
 * Read a color from an input stream.
 */
std::istream& operator>>(std::istream& is, color_t& c)
{
	unsigned int r, g, b;

	is >> r >> g >> b;
	c = (color_t) {
		(unsigned char) r,
		(unsigned char) g,
		(unsigned char) b
	};

	return is;
}

/**
 * Construct an empty image.
 *
 * @param cols        width of image in pixels
 * @param rows        height of image in pixels
 * @param brightness  brightness of image
 */
Image::Image(int cols, int rows, int brightness)
{
	this->cols = cols;
	this->rows = rows;
	this->brightness = brightness;
	this->pixels = new color_t[rows * cols];
}

/**
 * Construct a default image.
 */
Image::Image()
{
	this->cols = 0;
	this->rows = 0;
	this->brightness = 0;
	this->pixels = 0;
}

/**
 * Destruct an image.
 */
Image::~Image()
{
	delete[] this->pixels;
}

void swap(Image& lhs, Image& rhs)
{
	std::swap(lhs.cols, rhs.cols);
	std::swap(lhs.rows, rhs.rows);
	std::swap(lhs.brightness, rhs.brightness);
	std::swap(lhs.pixels, rhs.pixels);
}

/**
 * Assignment operator implemented with the "copy-and-swap" pattern.
 */
Image& Image::operator=(Image& rhs)
{
	swap(*this, rhs);

	return *this;
}

/**
 * Get the pixel width of an image.
 */
int Image::get_cols() const
{
	return this->cols;
}

/**
 * Get the pixel height of an image.
 */
int Image::get_rows() const
{
	return this->rows;
}

/**
 * Get the brightness of an image.
 */
int Image::get_brightness() const
{
	return this->brightness;
}

/**
 * Load an image from a PPM file.
 */
void Image::load(const char* fname)
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
	file.read((char*) this->pixels, this->rows * this->cols * sizeof(color_t));
	if ( !file ) {
		throw std::runtime_error("PPM file truncated");
	}

	file.close();
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