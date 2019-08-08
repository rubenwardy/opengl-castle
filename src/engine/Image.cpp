#include "Image.hpp"
#include <stb_image.h>

bool Image::load(const char *path) {
	data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (!data) {
		printf("Error! unable to load image\n");
		return false;
	}

	return true;
}


Image::~Image() {
	if (data) {
		stbi_image_free(data);
		data = nullptr;
	}
}
