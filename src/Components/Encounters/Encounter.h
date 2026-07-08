#pragma once
#include "../Base/GameObjectComponent.h"
#include "UnitHolder.h"

class Encounter : public GameObjectComponent {
	public:
		UnitHolder* GetHolders();
		UnitHolder GetHolders(int id);

		using GameObjectComponent::GameObjectComponent;

		Encounter(GameObjectBase* owner);
		~Encounter();
	private:
		UnitHolder* _holders;
};