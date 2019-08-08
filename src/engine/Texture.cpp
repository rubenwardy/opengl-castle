#include "Texture.hpp"

#include "gl.hpp"

void Texture::load(const Image &image) {
	glGenTextures(1, &handle);
	bind();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getSize().x, image.getSize().y, 0, GL_RGB, GL_UNSIGNED_BYTE, image.getData());
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::bind() const {
	glBindTexture(GL_TEXTURE_2D, handle);
}

void Texture::unload() {
	glDeleteTextures(1, &handle);
	handle = 0;
}
