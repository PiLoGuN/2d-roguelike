#include "Encounter.h"

UnitHolder* Encounter::GetHolders() {
	return _holders;
}
UnitHolder Encounter::GetHolders(int id) {
	return _holders[id];
}

Encounter::Encounter(GameObjectBase* owner) {
	//GameObjectComponent::GameObjectComponent(owner);
	_holders = new UnitHolder;
}
Encounter::~Encounter() {
	delete[] _holders;
}
