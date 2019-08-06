#include <fstream>
#include <iostream>
#include "Shader.hpp"
#include "gl.hpp"

Shader::Shader(ShaderType type, const char *source) {
	handle = glCreateShader(type);
	glShaderSource(handle, 1, &source, NULL);
	glCompileShader(handle);

	int  success;
	char infoLog[512];
	glGetShaderiv(handle, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(handle, 512, NULL, infoLog);
		std::cout << "Failed to compile shader:\n" << infoLog << "\nSource:\n" << source << std::endl;
	}
}

Shader Shader::Load(ShaderType type, const std::string &path) {
	std::ifstream t(path);
	std::string str((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());

	return Shader(type, str.c_str());
}


Shader::~Shader() {
	glDeleteShader(handle);
}
