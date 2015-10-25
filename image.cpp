/**
 * @file   image.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of an image.
 */
#include "image.h"
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * Construct an image from a PPM file.
 *
 * @param fname name of PPM file to read
 */
Image::Image(char* fname)
{
	ifstream file(fname, ios_base::binary);
	string header;
	int cols, rows, brightness;

	/* check for the PPM header */
	file >> header;
	if ( header != "P6" ) {
		throw runtime_error("PPM file does not start with \"P6\"");
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
	this->image = new pixel_t[rows * cols];

	/* read pixels */
	file.read((char*) this->image, rows * cols * sizeof(pixel_t));
	if ( !file ) {
		throw runtime_error("PPM file truncated");
	}

	file.close();
}

/**
 * Destruct an image.
 */
Image::~Image()
{
	delete[] this->image;
}

/**
 * Write an image to a PPM file.
 *
 * @param fname  name of PPM file to write
 */
void Image::write(char* fname) const
{
	ofstream file(fname, ios_base::binary);

	file << "P6 "
	     << this->cols << ' '
	     << this->rows << ' '
	     << this->brightness << '\n';
	file.write((char*) this->image, this->rows * this->cols * sizeof(pixel_t));

	file.close();
}