#include "Node.hpp"
#include "Component.hpp"

void Node::update(float delta) {
	for (const auto &component : _components) {
		component.second->update(delta);
	}
}

void Node::updateGlobalPosition() {
	_global_position = _position;
	if (_parent) {
		_position += _parent->getGlobalPosition();
	}

	for (const auto &child : _children) {
		child->updateGlobalPosition();
	}
}
