#include "Encounter.h"

UnitHolder* Encounter::GetHolders() const {
	return _holders;
}
UnitHolder Encounter::GetHolders(const int id) const {
	return _holders[id];
}

Encounter::Encounter(GameObjectBase* owner) : GameObjectComponent(owner) {
	//GameObjectComponent::GameObjectComponent(owner);
	_holders = new UnitHolder[2];
}
Encounter::~Encounter() {
	delete[] _holders;
}
