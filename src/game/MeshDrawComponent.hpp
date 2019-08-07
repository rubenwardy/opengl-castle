#pragma once

#include "../graph/Component.hpp"
#include "../engine/ShaderProgram.hpp"

class MeshDrawComponent : public Component {
	unsigned int vbo, ebo, vao;
	const ShaderProgram &shader;

public:
	MeshDrawComponent(Node::Ptr node, const ShaderProgram &shader);

	void update(float delta) override;
	void draw() const;

	static const std::string className;
};

