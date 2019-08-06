#pragma once

#include <cstddef>

enum VBOType {
	ARRAY_BUFFER = 0x8892,
	ELEMENT_ARRAY_BUFFER = 0x8893
};

enum VBODrawMode {
	STREAM = 0x88E0,
	STATIC = 0x88E4,
	DYNAMIC= 0x88E8
};

class VBO {
	unsigned int handle;
	VBOType type;
	VBODrawMode drawMode;

public:
	explicit VBO(VBOType type = ARRAY_BUFFER, VBODrawMode drawMode = STATIC);
	void bind();
	void setData(float *vertices, size_t size);
};
