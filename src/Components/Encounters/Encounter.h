#pragma once
#include "../Base/GameObjectComponent.h"
#include "UnitHolder.h"

class Encounter : public GameObjectComponent {
	public:
		UnitHolder* GetHolders() const;
		UnitHolder GetHolders(const int id) const;

		using GameObjectComponent::GameObjectComponent;

		Encounter(GameObjectBase* owner);
		~Encounter();
	private:
		UnitHolder* _holders;
};