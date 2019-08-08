#pragma once
#include <glm/glm.hpp>

class Image {
	int width = 0;
	int height = 0;
	int nrChannels = 0;
	unsigned char *data = nullptr;

public:
	Image() = default;
	explicit Image(const char *path) { load(path); }
	Image(const Image &other) = delete;
	~Image();

	bool load(const char *path);

	unsigned char *getData() const { return data; }
	glm::ivec2 getSize() const { return { width, height }; }
	bool isLoaded() const { return data != nullptr; }
};
