#pragma once

#include <glm/glm.hpp>

class Shader {
	unsigned int handle;

public:
	Shader(const std::string &vpath, const std::string &fpath);
	void use() const;

	void setUniform(const std::string& name, glm::mat4 mat4) const;
};
