/**
 * @file   Image.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of an image.
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

	// TODO: implement array access, double if possible
	int get_cols() const;
	int get_rows() const;
	int get_brightness() const;

	void load(const char* fname);
	void write(const char* fname) const;
	// Image duotone(const color_t& tint);
};

#endif