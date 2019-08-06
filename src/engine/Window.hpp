#pragma once

#include <glm/glm.hpp>

struct GLFWwindow;
class Window {
	GLFWwindow *window = nullptr;
public:
	Window();
	~Window();

	bool run();
	void swapBuffers();
	void clear(const glm::vec4 &color);
};
