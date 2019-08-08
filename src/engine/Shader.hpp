#pragma once

class Shader {
	unsigned int handle;

public:
	Shader(const std::string &vpath, const std::string &fpath);
	void use() const;
};
