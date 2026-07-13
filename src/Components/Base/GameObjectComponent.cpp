#include "GameObjectComponent.h"
//#include "../../Base/GameObjectBase.h"

GameObjectBase* GameObjectComponent::GetOwner() {
	return _owner.get();
}
std::shared_ptr<GameObjectBase> GameObjectComponent::GetOwnerSmart() {
	return _owner;
}

GameObjectComponent::GameObjectComponent() {
	_owner = nullptr;
}
GameObjectComponent::GameObjectComponent(std::shared_ptr<GameObjectBase> owner) {
	_owner = owner;
	std::cout << _owner << std::endl;
}