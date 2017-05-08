#include "Scene.h"
#include <exception>
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
	if ( argc != 3 ) {
		std::cerr << "usage: ./ray [scene-file] [image-file]\n";
		return 1;
	}

	/* open scene file */
	std::ifstream in(argv[1]);
	if ( !in ) {
		std::cerr << "error: could not open scene file \"" << argv[1] << "\"\n";
		return 1;
	}

	try {
		Scene scene;

		/* load and dump scene */
		in >> scene;
		std::clog << scene;
		
		/* render scene to PPM image */
		scene.render();
		scene.get_image()->write(argv[2]);
	}
	catch ( std::exception& e ) {
		std::cerr << "error: " << e.what() << '\n';
	}

	return 0;
}