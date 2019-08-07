#include "engine/Window.hpp"
#include "engine/Shader.hpp"
#include "engine/ShaderProgram.hpp"
#include "graph/Node.hpp"
#include "game/MeshDrawComponent.hpp"


int main() {
	Window window;

	ShaderProgram shaderProgram;
	shaderProgram.attach(Shader::Load(ShaderType::VERTEX, "assets/shaders/base.vert.glsl"));
	shaderProgram.attach(Shader::Load(ShaderType::FRAGMENT, "assets/shaders/base.frag.glsl"));
	shaderProgram.link();

	auto root = std::make_shared<Node>();
	{
		auto square = std::make_shared<Node>();
		square->addComponent<MeshDrawComponent>(new MeshDrawComponent(square, shaderProgram));
		root->addChild(square);
	}

	while (window.run()) {
		window.clear({ 0.2f, 0.3f, 0.3f, 1.0f });

		root->recurseComponents<MeshDrawComponent>([](auto x) {
			// TODO: visibility
			x->draw();
			return true;
		});

		window.swapBuffers();
	}
}
