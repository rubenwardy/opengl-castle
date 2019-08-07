#include <utility>

#pragma once

#include "Node.hpp"

class Component {
protected:
	Node::Ptr node;

public:
	explicit Component(Node::Ptr node):
		node(std::move(node)) {}

	virtual void update(float delta) = 0;
};

