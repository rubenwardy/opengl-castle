#include "engine/Window.hpp"
#include "engine/Shader.hpp"
#include "engine/ShaderProgram.hpp"
#include "engine/VBO.hpp"


int main() {
	Window window;

	ShaderProgram shaderProgram;
	shaderProgram.attach(Shader::Load(ShaderType::VERTEX, "assets/shaders/base.vert.glsl"));
	shaderProgram.attach(Shader::Load(ShaderType::FRAGMENT, "assets/shaders/base.frag.glsl"));
	shaderProgram.link();

	VBO vbo;
	float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f
	};
	vbo.setData(&vertices[0], 9);

	while (window.run()) {
		window.swapBuffers();
		window.clear({ 0.2f, 0.3f, 0.3f, 1.0f });
	}


}
