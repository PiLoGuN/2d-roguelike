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

std::shared_ptr<GameObjectBase> GameObjectBase::GetParent() {
	return _parent;
}
void GameObjectBase::SetParent(std::shared_ptr<GameObjectBase> parent) {
	_localPosition = this->GetGlobalPosition() - parent->GetGlobalPosition();
	_parent = parent;
}

Vector2f GameObjectBase::GetPosition() const {
	return _localPosition;
}
Vector2f GameObjectBase::GetGlobalPosition() {
	std::shared_ptr<GameObjectBase> iterObject = this->GetParent();
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

void GameObjectBase::AddComponent(ComponentBase& component) {
	std::cout << "START" << std::endl;
	//components.push_back(std::make_shared<ComponentBase>(component));
	components.push_back(&component);
	_componentCount++;
	//std::cout << "ComponentCount " << _componentCount << std::endl;
}
void GameObjectBase::RemoveComponent(int id) {
	components.erase(components.begin() + id);
	_componentCount--;
}
void GameObjectBase::RemoveComponent(ComponentBase& component) {
	for (size_t i = 0; i < _componentCount; i++){
		if (components[i] != &component)
			continue;

		components.erase(components.begin() + i);
		return;
	}
	_componentCount--;
}
int GameObjectBase::GetComponentCount() const {
	return _componentCount;
}


void GameObjectBase::Start() {
	for (size_t i = 0; i < GetComponentCount(); i++){
		components[i]->Start();
	}
}

void GameObjectBase::Update(const float dTime, const UpdateData& data) {
	for (size_t i = 0; i < GetComponentCount(); i++){
		components[i]->Update(dTime, data);
	}
}



