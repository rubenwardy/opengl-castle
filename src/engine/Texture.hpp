#pragma once

#include "Image.hpp"

class Texture {
	unsigned int handle = 0;
public:
	Texture() = default;
	explicit Texture(const Image &image) { load(image); }
	Texture(const Texture &texture) = delete;
	~Texture() { unload(); }

	void load(const Image &image);
	void bind() const;
	void unload();
};


