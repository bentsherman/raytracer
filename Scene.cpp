/**
 * @file   Scene.cpp
 * @author Ben Shealy
 *
 * @section DESCRIPTION
 *
 * Implementation of a scene.
 */
#include "Scene.h"
#include "Plane.h"
#include "Sphere.h"
#include <stdexcept>

/**
 * Destruct the scene.
 */
Scene::~Scene()
{
	for ( std::list<SceneObject*>::iterator iter = this->objects.begin();
			iter != this->objects.end(); iter++ ) {
		delete *iter;
	}

	delete this->image;
}

/**
 * Generate a ray from the window's viewpoint to a pixel in the window.
 *
 * @param row  row of the pixel
 * @param col  col of the pixel
 * @param vector from the viewpoint to the pixel
 */
Vector Scene::gen_ray(int row, int col) const
{
	// reverse row to match row in image
	row = this->image->get_rows() - 1 - row;

	Vector V(
		this->window.get_width() * (col / (this->image->get_cols()-1.0) - 0.5),
		this->window.get_height() * (row / (this->image->get_rows()-1.0) - 0.5),
		0
	);

	return (V - this->window.get_viewpoint()).unit();
}

/**
 * Trace a ray through the scene.
 *
 * @param V     origin of the ray
 * @param D     direction of the ray
 * @param dist  total distance traveled by the ray
 * @param composite intensity of the light encountered by the ray
 */
Vector Scene::trace_ray(const Vector& V, const Vector& D, double dist)
{
	hitinfo_t hit;
	SceneObject* object = this->closest(V, D, &hit);

	if ( object ) {
		dist += hit.distance;

		/* compute color from object color and ambient intensity */
		Vector intensity(
			object->get_color().r * this->window.get_ambient().get_x(),
			object->get_color().g * this->window.get_ambient().get_y(),
			object->get_color().b * this->window.get_ambient().get_z()
		);

		/* scale intensity to color and darken by distance from viewpoint */
		return intensity / (255 * dist);
	}

	return Vector();
}

/**
 * Find the closest scene object hit by a ray.
 *
 * @param V    origin of the ray
 * @param D    direction of the ray
 * @param hit  pointer to hit parameters
 * @return pointer to closest hit scene object, or NULL if nothing was hit
 */
SceneObject* Scene::closest(const Vector& V, const Vector& D, hitinfo_t* hit)
{
	SceneObject* closest = 0;

	for ( std::list<SceneObject*>::iterator iter = this->objects.begin();
			iter != this->objects.end(); iter++ ) {

		/* check each scene object for a hit */
		hitinfo_t hit_i;
		bool result = (*iter)->hits(V, D, &hit_i);

		/* update hitinfo if a closer hit is found */
		if ( result && (!closest || hit_i.distance < hit->distance) ) {
			*hit = hit_i;
			closest = *iter;
		}
	}

	return closest;
}

/**
 * Render a single pixel in the scene's image.
 *
 * @param row  row of the pixel
 * @param col  column of the pixel
 * @return the rendered color of the pixel
 */
color_t Scene::render_pixel(int row, int col)
{
	Vector V = this->window.get_viewpoint();
	Vector D = this->gen_ray(row, col);
	Vector intensity = this->trace_ray(V, D, 0);

	/* clamp the color intensity to 1 */
	if ( intensity.get_x() > 1.0 ) intensity.set_x(1.0);
	if ( intensity.get_y() > 1.0 ) intensity.set_y(1.0);
	if ( intensity.get_z() > 1.0 ) intensity.set_z(1.0);

	/* convert intensity to color */
	return (color_t) {
		(unsigned char)(255 * intensity.get_x()),  // TODO: could also use min() here
		(unsigned char)(255 * intensity.get_y()),
		(unsigned char)(255 * intensity.get_z())
	};
}

/**
 * Render the scene into an image.
 *
 * The scene renders an image by "firing" a ray through the window for
 * each pixel in the image. The color of each pixel is determined by how the
 * ray interacts with the objects and lights in the scene.
 */
void Scene::render()
{
	Image& image = *(this->image);

	for ( int i = 0; i < this->image->get_rows(); i++ ) {
		for ( int j = 0; j < this->image->get_cols(); j++ ) {
			image[i][j] = render_pixel(i, j);
		}
	}
}

/**
 * Get the scene's image.
 *
 * @return this scene's image
 */
Image* Scene::get_image() const
{
	return this->image;
}

/**
 * Write the scane to an output stream.
 *
 * @param os
 */
std::ostream& operator<<(std::ostream& os, const Scene& scene)
{
	os << scene.window << '\n';

	for ( std::list<SceneObject*>::const_iterator iter = scene.objects.begin();
			iter != scene.objects.end(); iter++ ) {
		os << **iter << '\n';
	}

	for ( std::list<PointLight>::const_iterator iter = scene.lights.begin();
			iter != scene.lights.end(); iter++ ) {
		os << *iter << '\n';
	}

	return os;
}

/**
 * Read the scane from an input stream.
 *
 * @param is
 */
std::istream& operator>>(std::istream& is, Scene& scene)
{
	std::string token;

	while ( is >> token ) {
		if ( token == "window" ) {
			is >> scene.window;

			scene.image = new Image(
				scene.window.get_cols(),
				scene.window.get_cols() * scene.window.get_height()
					/ scene.window.get_width(),
				255
			);
		}
		else if ( token == "plane" ) {
			Plane* plane = new Plane;

			is >> *plane;
			scene.objects.push_back(plane);
		}
		else if ( token == "sphere" ) {
			Sphere* sphere = new Sphere;

			is >> *sphere;
			scene.objects.push_back(sphere);
		}
		else if ( token == "pointlight" ) {
			PointLight light;

			is >> light;
			scene.lights.push_back(light);
		}
		else {
			throw std::runtime_error("unknown token \"" + token + "\"");
		}
	}

	return is;
}