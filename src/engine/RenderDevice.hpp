#pragma once

#include <memory>
#include "Window.hpp"


class RenderDevice {
	Window window;
	glm::mat4 viewProjection;

public:
	RenderDevice();
	RenderDevice(const RenderDevice &other) = delete;

	inline Window &getWindow() { return window; }
	inline const glm::mat4 &getViewProjectionMatrix() const { return viewProjection; }

private:
	void updateViewProjectionMatrix();
};


