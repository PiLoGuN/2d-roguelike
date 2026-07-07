#include "GameObjectComponent.h"
//#include "../../Base/GameObjectBase.h"

GameObjectBase* GameObjectComponent::GetOwner() {
	return _owner;
}

GameObjectComponent::GameObjectComponent(GameObjectBase* owner) {
	_owner = owner;
}