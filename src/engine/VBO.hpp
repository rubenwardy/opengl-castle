#pragma once

#include <cstddef>
#include "consts.hpp"


class VBO {
	unsigned int handle;
	VBOType type;
	VBODrawMode drawMode;

public:
	explicit VBO(VBOType type = ARRAY_BUFFER, VBODrawMode drawMode = STATIC);
	void bind();
	void unbind();
	void setData(float *vertices, size_t size);
};
