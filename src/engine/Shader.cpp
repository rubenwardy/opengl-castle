#include <assert.h>
#include <iostream>
#include <fstream>
#include "Shader.hpp"
#include "gl.hpp"

bool loadShader(int &handle, int type, const std::string &path) {
	std::ifstream t(path);
	std::string str((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());
	const char *source = str.c_str();

	handle = glCreateShader(type);
	glShaderSource(handle, 1, &source, NULL);
	glCompileShader(handle);

	int  success;
	char infoLog[512];
	glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(handle, 512, NULL, infoLog);
		std::cout << "Failed to compile shader:\n" << infoLog << "\nSource:\n" << source << std::endl;
		return false;
	}

	return true;
}

Shader::Shader(const std::string &vpath, const std::string &fpath) {
	int vert, frag;
	loadShader(vert, GL_VERTEX_SHADER, vpath);
	loadShader(frag, GL_FRAGMENT_SHADER, fpath);

	handle = glCreateProgram();
	glAttachShader(handle, vert);
	glAttachShader(handle, frag);

	glLinkProgram(handle);

	int success;
	glGetProgramiv(handle, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(handle, 512, NULL, infoLog);
		std::cout << "Failed to compile shader program:\n" << infoLog << std::endl;
	}
}

void Shader::use() const {
	glUseProgram(handle);
}

