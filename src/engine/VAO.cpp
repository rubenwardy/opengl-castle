#include "VAO.hpp"
#include "gl.hpp"

VAO::VAO() {
	glGenVertexArrays(1, &handle);
}

void VAO::bind() {
	glBindVertexArray(handle);
}

void VAO::unbind() {
	glBindVertexArray(0);
}

void VAO::draw() {
	bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
