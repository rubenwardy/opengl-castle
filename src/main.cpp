#include <iostream>
#include "engine/Window.hpp"
#include "engine/Shader.hpp"
#include "engine/Shader.hpp"
#include "graph/Node.hpp"
#include "game/MeshDrawComponent.hpp"
#include "tests/tests.hpp"


int main() {
	if (!TestRunner::RunTests()) {
		std::cerr << "Some tests failed" << std::endl;
		return 0;
	}

	Window window;
	Shader shaderProgram("assets/shaders/base.vert.glsl", "assets/shaders/base.frag.glsl");

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
