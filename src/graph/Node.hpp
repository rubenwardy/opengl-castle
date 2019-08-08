#pragma once

#include <memory>
#include <vector>
#include <unordered_map>
#include <glm/vec3.hpp>
#include <functional>


class Component;
class Node {
public:
	Node() = default;
	Node(const Node &other) = delete;

	using Ptr = std::shared_ptr<Node>;

	void update(float delta);

	void updateGlobalPosition();
	glm::vec3 getGlobalPosition() const { return _global_position; }
	void setPosition(glm::vec3 pos) {
		_position = pos;
		updateGlobalPosition();
	}

	template<typename T>
	void addComponent(T *comp) {
		_components[T::className] = std::unique_ptr<Component>(comp);
	}

	template<typename T, typename... _Args>
	inline T *addComponent(_Args&&... __args) {
		auto ptr = std::make_unique<T>(std::forward<_Args>(__args)...);
		T *rptr = ptr.get();

		_components[T::className] = std::move(ptr);
		return rptr;
	}

	template<class T>
	void recurseComponents(const std::function<bool(T*)> &cb) {
		auto &name = T::className;
		auto it = _components.find(name);
		if (it != _components.end()) {
			Component *ptr = it->second.get();
			if (!cb(dynamic_cast<T*>(ptr))) {
				return;
			}
		}

		for (auto &child : _children) {
			child->recurseComponents<T>(cb);
		}
	}

	void addChild(const Ptr &child) {
		_children.push_back(child);
		child->_parent = this;
		child->updateGlobalPosition();
	}

protected:
	std::vector<Ptr> _children;
	std::unordered_map<std::string, std::unique_ptr<Component>> _components;
	glm::vec3 _position;
	glm::vec3 _global_position;
	Node *_parent = nullptr;

};
