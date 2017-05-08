/**
 * @file   Image.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of an image.
 *
 * For simplicity, it is assumed that Image objects will be managed as a
 * pointer instead of a value, so the copy constructor and assignment
 * operator are not defined explicitly.
 */
#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>

typedef struct color_t {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} color_t;

std::ostream& operator<<(std::ostream& os, const color_t& c);
std::istream& operator>>(std::istream& is, color_t& c);

// TODO: consider file formats other than PPM
class Image {
private:
	int cols;
	int rows;
	int brightness;
	color_t* pixels;

public:
	Image(int cols, int rows, int brightness);
	Image();
	~Image();

	int get_cols() const;
	int get_rows() const;
	int get_brightness() const;

	      color_t* operator[](unsigned i);
	const color_t* operator[](unsigned i) const;

	void load(const char* fname);
	void write(const char* fname) const;
	// Image duotone(const color_t& tint);
};

#endif