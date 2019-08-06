#include "VBO.hpp"
#include "gl.hpp"

VBO::VBO(VBOType type, VBODrawMode drawMode):
		type(type), drawMode(drawMode) {
	glGenBuffers(1, &handle);
}

void VBO::bind() {
	glBindBuffer(type, handle);
}

void VBO::setData(float *vertices, size_t size) {
	glBufferData(type, size, vertices, drawMode);
}
