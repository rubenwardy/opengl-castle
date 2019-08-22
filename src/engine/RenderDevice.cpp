#include "RenderDevice.hpp"
#include "Window.hpp"

#include <glm/gtc/matrix_transform.hpp>

RenderDevice::RenderDevice():
		window(), viewProjection() {
	updateViewProjectionMatrix();
}

void RenderDevice::updateViewProjectionMatrix() {
	//          model         ((view            perspective))
	//  model --------> world -------> camera --------------> screen
	//
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

	auto size = window.getSize();
	float ratio = (float)size.x / (float)size.y;
	viewProjection = glm::perspective(glm::radians(45.0f), ratio, 0.1f, 100.0f) * view;
}
