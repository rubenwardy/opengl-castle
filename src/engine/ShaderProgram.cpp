#include <assert.h>
#include <iostream>
#include "ShaderProgram.hpp"
#include "gl.hpp"

ShaderProgram::ShaderProgram() {
	handle = glCreateProgram();
}

void ShaderProgram::attach(const Shader &shader) {
	assert(!locked);
	glAttachShader(handle, shader);
}

void ShaderProgram::link() {
	glLinkProgram(handle);
	locked = true;

	int success;
	glGetProgramiv(handle, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(handle, 512, NULL, infoLog);
		std::cout << "Failed to compile shader program:\n" << infoLog << std::endl;
	}
}

void ShaderProgram::use() const {
	glUseProgram(handle);
}
