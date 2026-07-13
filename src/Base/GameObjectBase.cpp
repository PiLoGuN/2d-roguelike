#include "GameObjectBase.h"

GameObjectBase::GameObjectBase() {
	SetPosition(Vector2f(0,0));
	std::cout << "ONE 0 0" << std::endl;
	std::cout << GetPosition().x << " " << GetPosition().y << std::endl;
}

GameObjectBase::GameObjectBase(Vector2f pos) {
	SetPosition(pos);
	std::cout << "TWO" << pos.x << pos.y << std::endl;
}

GameObjectBase* GameObjectBase::GetParent() {
	return _parent.get();
}
void GameObjectBase::SetParent(std::shared_ptr<GameObjectBase> parent) {
	_localPosition = this->GetGlobalPosition() - parent->GetGlobalPosition();
	std::cout << parent.get() << std::endl;
	_parent = parent;
}


Vector2f GameObjectBase::GetPosition() const {
	return _localPosition;
}
Vector2f GameObjectBase::GetGlobalPosition() {
	GameObjectBase* iterObject = this->GetParent();
	Vector2f position = this->GetPosition();
	while (iterObject != NULL) {
		position += iterObject->GetPosition();
		iterObject = iterObject->GetParent();
	}
	return position;
}
void GameObjectBase::SetPosition(Vector2f position) {
	_localPosition = position;
}


void GameObjectBase::AddComponent(std::shared_ptr<ComponentBase> component) {
	std::cout << "START" << std::endl;
	_components.push_back(component);
	_componentCount++;
}
void GameObjectBase::RemoveComponent(int id) {
	_components.erase(_components.begin() + id);
	_componentCount--;
}
//Raw since i basically only need the address
void GameObjectBase::RemoveComponent(ComponentBase* component) {
	for (size_t i = 0; i < _componentCount; i++){
		if (_components[i].get() != component)
			continue;

		_components.erase(_components.begin() + i);
		return;
	}
	_componentCount--;
}
std::shared_ptr<ComponentBase> GameObjectBase::GetComponent(int id) {
	return _components[id];
}
int GameObjectBase::GetComponentCount() const {
	return _componentCount;
}


void GameObjectBase::Start() {
	std::cout << "Start's start" << std::endl;
	for (size_t i = 0; i < GetComponentCount(); i++) {
		std::cout << "Comp: ";
		std::cout << _components[i] << std::endl;
		_components[i]->Start();
	}
	std::cout << "Start's end" << std::endl;
}

void GameObjectBase::Update(const float dTime, const UpdateData& data) {
	for (size_t i = 0; i < GetComponentCount(); i++){
		_components[i]->Update(dTime, data);
	}
}



