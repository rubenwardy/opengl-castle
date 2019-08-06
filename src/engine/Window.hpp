#pragma once

struct Color {
	float r, g, b, a;
};

struct GLFWwindow;
class Window {
	GLFWwindow *window = nullptr;
public:
	Window();
	~Window();

	bool run();
	void swapBuffers();
	void clear(const Color &color);
};
