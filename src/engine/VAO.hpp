#pragma once

class VAO {
	unsigned int handle;

public:
	VAO();
	void bind();
	void unbind();
	void draw();
};
