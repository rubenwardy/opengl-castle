#include "engine/Window.hpp"
#include "engine/Shader.hpp"
#include "engine/ShaderProgram.hpp"
#include "engine/VBO.hpp"
#include "engine/VAO.hpp"


int main() {
	Window window;

	ShaderProgram shaderProgram;
	shaderProgram.attach(Shader::Load(ShaderType::VERTEX, "assets/shaders/base.vert.glsl"));
	shaderProgram.attach(Shader::Load(ShaderType::FRAGMENT, "assets/shaders/base.frag.glsl"));
	shaderProgram.link();

	VAO vao;
	VBO vbo;
	VBO ebo(ELEMENT_ARRAY_BUFFER);

	vao.bind();

	float vertices[] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left
	};
	unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
	};

	vbo.bind();
	ebo.bind();
	vbo.setData3(&vertices[0], sizeof(vertices));
	ebo.setData(&indices[0], sizeof(indices));
	vao.unbind();
	ebo.unbind();
	vbo.unbind();

	while (window.run()) {
		window.clear({ 0.2f, 0.3f, 0.3f, 1.0f });
		shaderProgram.use();
		vao.draw();
		window.swapBuffers();
	}
}
