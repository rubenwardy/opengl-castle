#pragma once

#include "../graph/Component.hpp"
#include "../engine/Shader.hpp"

class MeshDrawComponent : public Component {
	unsigned int vbo, ebo, vao, texture;
	const Shader &shader;

public:
	MeshDrawComponent(Node::Ptr node, const Shader &shader);

	void update(float delta) override;
	void draw() const;

	static const std::string className;
};

