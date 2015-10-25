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

typedef struct color_t {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} color_t;

// TODO: consider file formats other than PPM
class Image {
private:
	int cols;
	int rows;
	int brightness;
	color_t* pixels;

public:
	Image(const char* fname);
	~Image();

	// TODO: implement array access, double if possible

	void write(const char* fname) const;
	// Image duotone(const color_t& tint);
};

#endif