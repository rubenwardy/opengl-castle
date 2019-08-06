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
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
