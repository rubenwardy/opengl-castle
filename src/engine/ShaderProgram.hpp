#pragma once

#include "Shader.hpp"

class ShaderProgram {
	unsigned int handle;
	bool locked = false;

public:
	ShaderProgram();
	void attach(const Shader &shader);
	void link();
	void use() const;
};
