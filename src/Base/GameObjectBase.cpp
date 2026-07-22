#include "GameObjectBase.h"

GameObjectBase::GameObjectBase() {
	SetPosition(Vector2f(0,0));
}

GameObjectBase::GameObjectBase(Vector2f pos) {
	SetPosition(pos);
}

GameObjectBase* GameObjectBase::GetParent() {
	return _parent.get();
}
void GameObjectBase::SetParent(std::shared_ptr<GameObjectBase> parent) {
	_localPosition = this->GetGlobalPosition() - parent->GetGlobalPosition();
	std::cout << parent.get() << " NEW PARENT" << std::endl;
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

	for (size_t i = 0; i < transformUpdated.size(); i++)
	{
		transformUpdated[i]();
	}
}


void GameObjectBase::AddComponent(std::unique_ptr<ComponentBase> component) {
	_components.push_back(std::move(component));
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
ComponentBase& GameObjectBase::GetComponent(int id) {
	return *(_components[id]).get();
}
int GameObjectBase::GetComponentCount() const {
	return _componentCount;
}


void GameObjectBase::Start(const UpdateData& data) {
	for (size_t i = 0; i < GetComponentCount(); i++) {
		_components[i]->Start(data);
	}
}

void GameObjectBase::Update(const float dTime, const UpdateData& data) {
	//std::cout << GetComponentCount() << std::endl;
	for (size_t i = 0; i < GetComponentCount(); i++){
		//std::cout << _components[i]->GetName() << std::endl;
		_components[i]->Update(dTime, data);
	}
}

void GameObjectBase::RenderUpdate(const float dTime, const UpdateData& data) {
	for (size_t i = 0; i < GetComponentCount(); i++) {
		_components[i]->RenderUpdate(dTime, data);
	}
}



