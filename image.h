/**
 * @file   image.h
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Interface definition of an image.
 */
#ifndef IMAGE_H
#define IMAGE_H

typedef struct pixel_t {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} pixel_t;

// TODO: consider file formats other than PPM
class Image {
private:
	int cols;
	int rows;
	int brightness;
	pixel_t* image;

public:
	Image(char* fname);
	~Image();

	// TODO: implement array access, double if possible

	void write(char* fname) const;
	// Image duotone(pixel_t tint);
};

#endif