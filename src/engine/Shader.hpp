#pragma once

#include <string>

enum ShaderType {
	FRAGMENT = 0x8B30,
	VERTEX = 0x8B31
};

class Shader {
	unsigned int handle;

public:
	Shader(ShaderType type, const char *source);
	Shader(const Shader &other) = delete;
	~Shader();

	static Shader Load(ShaderType type, const std::string &path);

	operator unsigned int() const {
		return handle;
	}
};
