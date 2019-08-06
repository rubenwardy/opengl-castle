#include "VBO.hpp"
#include "gl.hpp"

VBO::VBO(VBOType type, VBODrawMode drawMode):
		type(type), drawMode(drawMode) {
	glGenBuffers(1, &handle);
}

void VBO::bind() {
	glBindBuffer(type, handle);
}

void VBO::unbind() {
	glBindBuffer(type, 0);
}

void VBO::setData(float *vertices, size_t size) {
	bind();
	glBufferData(type, size, vertices, drawMode);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	unbind();
}
