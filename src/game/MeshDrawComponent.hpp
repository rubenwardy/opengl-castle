#pragma once

#include "../graph/Component.hpp"
#include "../engine/Shader.hpp"
#include "../engine/Texture.hpp"
#include "../engine/RenderDevice.hpp"

class MeshDrawComponent : public Component {
	unsigned int vbo, ebo, vao;
	Texture texture;
	const Shader &shader;
	RenderDevice *device;

public:
	MeshDrawComponent(Node::Ptr node, RenderDevice *device, const Shader &shader);

	void update(float delta) override;
	void draw() const;

	static const std::string className;
};

