#include "GameObjectComponent.h"
//#include "../../Base/GameObjectBase.h"

std::shared_ptr<GameObjectBase> GameObjectComponent::GetOwner() {
	return _owner;
}

GameObjectComponent::GameObjectComponent() {
	_owner = nullptr;
}
GameObjectComponent::GameObjectComponent(GameObjectBase& owner) {
	_owner = std::make_shared<GameObjectBase>(owner);
	std::cout << _owner;
}