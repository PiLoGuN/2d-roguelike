#include "GameObjectBase.h"

GameObjectBase* GameObjectBase::GetParent() const {
	return _parent;
}
void GameObjectBase::SetParent(GameObjectBase* parent) {
	_localPosition = this->GetGlobalPosition() - parent->GetGlobalPosition();
	_parent = parent;
}

Vector2f GameObjectBase::GetPosition() const {
	return _localPosition;
}
Vector2f GameObjectBase::GetGlobalPosition() const {
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


void GameObjectBase::Start() {
	for (size_t i = 0; i < componentCount; i++)
	{
		(*components[i]).Start();
	}
}

void GameObjectBase::Update(float dTime) {
	for (size_t i = 0; i < componentCount; i++)
	{
		(*components[i]).Update(dTime);
	}
}



